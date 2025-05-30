#ifndef LOGGER_H
#define LOGGER_H

#include "core/io/file_access.h"
#include "core/string/ustring.h"
#include "core/templates/vector.h"

#include <stdarg.h>

class IRegEx;

class Logger {
protected:
	bool should_log(bool p_err);

	static bool _flush_stdout_on_print;

public:
	enum ErrorType {
		ERR_ERROR,
		ERR_WARNING,
		ERR_SCRIPT,
		ERR_SHADER
	};

	static void set_flush_stdout_on_print(bool value);

	virtual void logv(const char *p_format, va_list p_list, bool p_err) _PRINTF_FORMAT_ATTRIBUTE_2_0 = 0;
	virtual void log_error(const char *p_function, const char *p_file, int p_line, const char *p_code, const char *p_rationale, bool p_editor_notify = false, ErrorType p_type = ERR_ERROR);

	void logf(const char *p_format, ...) _PRINTF_FORMAT_ATTRIBUTE_2_3;
	void logf_error(const char *p_format, ...) _PRINTF_FORMAT_ATTRIBUTE_2_3;

	virtual ~Logger() {}
};

/**
 * Writes messages to stdout/stderr.
 */
class StdLogger : public Logger {
public:
	virtual void logv(const char *p_format, va_list p_list, bool p_err) override _PRINTF_FORMAT_ATTRIBUTE_2_0;
	virtual ~StdLogger() {}
};

/**
 * Writes messages to the specified file. If the file already exists, creates a copy (backup)
 * of it with timestamp appended to the file name. Maximum number of backups is configurable.
 * When maximum is reached, the oldest backups are erased. With the maximum being equal to 1,
 * it acts as a simple file logger.
 */
class RotatedFileLogger : public Logger {
	String base_path;
	int max_files;

	Ref<FileAccess> file;

	void clear_old_backups();
	void rotate_file();

	Ref<IRegEx> strip_ansi_regex;

public:
	explicit RotatedFileLogger(const String &p_base_path, int p_max_files = 10);

	virtual void logv(const char *p_format, va_list p_list, bool p_err) override _PRINTF_FORMAT_ATTRIBUTE_2_0;
};

class CompositeLogger : public Logger {
	Vector<Logger *> loggers;

public:
	explicit CompositeLogger(const Vector<Logger *> &p_loggers);

	virtual void logv(const char *p_format, va_list p_list, bool p_err) override _PRINTF_FORMAT_ATTRIBUTE_2_0;
	virtual void log_error(const char *p_function, const char *p_file, int p_line, const char *p_code, const char *p_rationale, bool p_editor_notify, ErrorType p_type = ERR_ERROR) override;

	void add_logger(Logger *p_logger);

	virtual ~CompositeLogger();
};

#endif // LOGGER_H
