/* WARNING, THIS FILE WAS GENERATED, DO NOT EDIT */
#ifndef TONEMAP_GLSL_GEN_H_RD
#define TONEMAP_GLSL_GEN_H_RD

#include "servers/rendering/renderer_rd/shader_rd.h"

class TonemapShaderRD : public ShaderRD {

public:

	TonemapShaderRD() {

		static const char _vertex_code[] = {
R"<!>(
#version 450

#VERSION_DEFINES

#ifdef USE_MULTIVIEW
#ifdef has_VK_KHR_multiview
#extension GL_EXT_multiview : enable
#endif
#endif

layout(location = 0) out vec2 uv_interp;

void main() {
	
	
	
	
	

	vec2 vertex_base;
	if (gl_VertexIndex == 0) {
		vertex_base = vec2(-1.0, -1.0);
	} else if (gl_VertexIndex == 1) {
		vertex_base = vec2(-1.0, 3.0);
	} else {
		vertex_base = vec2(3.0, -1.0);
	}
	gl_Position = vec4(vertex_base, 0.0, 1.0);
	uv_interp = clamp(vertex_base, vec2(0.0, 0.0), vec2(1.0, 1.0)) * 2.0; 
}

)<!>"
		};
		static const char _fragment_code[] = {
R"<!>(
#version 450

#VERSION_DEFINES

#ifdef USE_MULTIVIEW
#ifdef has_VK_KHR_multiview
#extension GL_EXT_multiview : enable
#define ViewIndex gl_ViewIndex
#else 
#define ViewIndex 0
#endif 
#endif 

layout(location = 0) in vec2 uv_interp;

#ifdef SUBPASS
layout(input_attachment_index = 0, set = 0, binding = 0) uniform subpassInput input_color;
#elif defined(USE_MULTIVIEW)
layout(set = 0, binding = 0) uniform sampler2DArray source_color;
#else
layout(set = 0, binding = 0) uniform sampler2D source_color;
#endif

layout(set = 1, binding = 0) uniform sampler2D source_auto_exposure;
#ifdef USE_MULTIVIEW
layout(set = 2, binding = 0) uniform sampler2DArray source_glow;
#else
layout(set = 2, binding = 0) uniform sampler2D source_glow;
#endif
layout(set = 2, binding = 1) uniform sampler2D glow_map;

#ifdef USE_1D_LUT
layout(set = 3, binding = 0) uniform sampler2D source_color_correction;
#else
layout(set = 3, binding = 0) uniform sampler3D source_color_correction;
#endif

#define FLAG_USE_BCS (1 << 0)
#define FLAG_USE_GLOW (1 << 1)
#define FLAG_USE_AUTO_EXPOSURE (1 << 2)
#define FLAG_USE_COLOR_CORRECTION (1 << 3)
#define FLAG_USE_FXAA (1 << 4)
#define FLAG_USE_DEBANDING (1 << 5)
#define FLAG_CONVERT_TO_SRGB (1 << 6)

layout(push_constant, std430) uniform Params {
	vec3 bcs;
	uint flags;

	vec2 pixel_size;
	uint tonemapper;
	uint pad;

	uvec2 glow_texture_size;
	float glow_intensity;
	float glow_map_strength;

	uint glow_mode;
	float glow_levels[7];

	float exposure;
	float white;
	float auto_exposure_scale;
	float luminance_multiplier;
}
params;

layout(location = 0) out vec4 frag_color;

#ifdef USE_GLOW_FILTER_BICUBIC

float w0(float a) {
	return (1.0f / 6.0f) * (a * (a * (-a + 3.0f) - 3.0f) + 1.0f);
}

float w1(float a) {
	return (1.0f / 6.0f) * (a * a * (3.0f * a - 6.0f) + 4.0f);
}

float w2(float a) {
	return (1.0f / 6.0f) * (a * (a * (-3.0f * a + 3.0f) + 3.0f) + 1.0f);
}

float w3(float a) {
	return (1.0f / 6.0f) * (a * a * a);
}


float g0(float a) {
	return w0(a) + w1(a);
}

float g1(float a) {
	return w2(a) + w3(a);
}


float h0(float a) {
	return -1.0f + w1(a) / (w0(a) + w1(a));
}

float h1(float a) {
	return 1.0f + w3(a) / (w2(a) + w3(a));
}

#ifdef USE_MULTIVIEW
vec4 texture2D_bicubic(sampler2DArray tex, vec2 uv, int p_lod) {
	float lod = float(p_lod);
	vec2 tex_size = vec2(params.glow_texture_size >> p_lod);
	vec2 pixel_size = vec2(1.0f) / tex_size;

	uv = uv * tex_size + vec2(0.5f);

	vec2 iuv = floor(uv);
	vec2 fuv = fract(uv);

	float g0x = g0(fuv.x);
	float g1x = g1(fuv.x);
	float h0x = h0(fuv.x);
	float h1x = h1(fuv.x);
	float h0y = h0(fuv.y);
	float h1y = h1(fuv.y);

	vec3 p0 = vec3((vec2(iuv.x + h0x, iuv.y + h0y) - vec2(0.5f)) * pixel_size, ViewIndex);
	vec3 p1 = vec3((vec2(iuv.x + h1x, iuv.y + h0y) - vec2(0.5f)) * pixel_size, ViewIndex);
	vec3 p2 = vec3((vec2(iuv.x + h0x, iuv.y + h1y) - vec2(0.5f)) * pixel_size, ViewIndex);
	vec3 p3 = vec3((vec2(iuv.x + h1x, iuv.y + h1y) - vec2(0.5f)) * pixel_size, ViewIndex);

	return (g0(fuv.y) * (g0x * textureLod(tex, p0, lod) + g1x * textureLod(tex, p1, lod))) +
			(g1(fuv.y) * (g0x * textureLod(tex, p2, lod) + g1x * textureLod(tex, p3, lod)));
}

#define GLOW_TEXTURE_SAMPLE(m_tex, m_uv, m_lod) texture2D_bicubic(m_tex, m_uv, m_lod)
#else 

vec4 texture2D_bicubic(sampler2D tex, vec2 uv, int p_lod) {
	float lod = float(p_lod);
	vec2 tex_size = vec2(params.glow_texture_size >> p_lod);
	vec2 pixel_size = vec2(1.0f) / tex_size;

	uv = uv * tex_size + vec2(0.5f);

	vec2 iuv = floor(uv);
	vec2 fuv = fract(uv);

	float g0x = g0(fuv.x);
	float g1x = g1(fuv.x);
	float h0x = h0(fuv.x);
	float h1x = h1(fuv.x);
	float h0y = h0(fuv.y);
	float h1y = h1(fuv.y);

	vec2 p0 = (vec2(iuv.x + h0x, iuv.y + h0y) - vec2(0.5f)) * pixel_size;
	vec2 p1 = (vec2(iuv.x + h1x, iuv.y + h0y) - vec2(0.5f)) * pixel_size;
	vec2 p2 = (vec2(iuv.x + h0x, iuv.y + h1y) - vec2(0.5f)) * pixel_size;
	vec2 p3 = (vec2(iuv.x + h1x, iuv.y + h1y) - vec2(0.5f)) * pixel_size;

	return (g0(fuv.y) * (g0x * textureLod(tex, p0, lod) + g1x * textureLod(tex, p1, lod))) +
			(g1(fuv.y) * (g0x * textureLod(tex, p2, lod) + g1x * textureLod(tex, p3, lod)));
}

#define GLOW_TEXTURE_SAMPLE(m_tex, m_uv, m_lod) texture2D_bicubic(m_tex, m_uv, m_lod)
#endif 

#else 

#ifdef USE_MULTIVIEW
#define GLOW_TEXTURE_SAMPLE(m_tex, m_uv, m_lod) textureLod(m_tex, vec3(m_uv, ViewIndex), float(m_lod))
#else 
#define GLOW_TEXTURE_SAMPLE(m_tex, m_uv, m_lod) textureLod(m_tex, m_uv, float(m_lod))
#endif 

#endif 


vec3 tonemap_reinhard(vec3 color, float white) {
	float white_squared = white * white;
	vec3 white_squared_color = white_squared * color;
	
	return (white_squared_color + color * color) / (white_squared_color + white_squared);
}

vec3 tonemap_filmic(vec3 color, float white) {
	
	
	
	const float exposure_bias = 2.0f;
	const float A = 0.22f * exposure_bias * exposure_bias; 
	const float B = 0.30f * exposure_bias;
	const float C = 0.10f;
	const float D = 0.20f;
	const float E = 0.01f;
	const float F = 0.30f;

	vec3 color_tonemapped = ((color * (A * color + C * B) + D * E) / (color * (A * color + B) + D * F)) - E / F;
	float white_tonemapped = ((white * (A * white + C * B) + D * E) / (white * (A * white + B) + D * F)) - E / F;

	return color_tonemapped / white_tonemapped;
}



vec3 tonemap_aces(vec3 color, float white) {
	const float exposure_bias = 1.8f;
	const float A = 0.0245786f;
	const float B = 0.000090537f;
	const float C = 0.983729f;
	const float D = 0.432951f;
	const float E = 0.238081f;

	
	const mat3 rgb_to_rrt = mat3(
			vec3(0.59719f * exposure_bias, 0.35458f * exposure_bias, 0.04823f * exposure_bias),
			vec3(0.07600f * exposure_bias, 0.90834f * exposure_bias, 0.01566f * exposure_bias),
			vec3(0.02840f * exposure_bias, 0.13383f * exposure_bias, 0.83777f * exposure_bias));

	const mat3 odt_to_rgb = mat3(
			vec3(1.60475f, -0.53108f, -0.07367f),
			vec3(-0.10208f, 1.10813f, -0.00605f),
			vec3(-0.00327f, -0.07276f, 1.07602f));

	color *= rgb_to_rrt;
	vec3 color_tonemapped = (color * (color + A) - B) / (color * (C * color + D) + E);
	color_tonemapped *= odt_to_rgb;

	white *= exposure_bias;
	float white_tonemapped = (white * (white + A) - B) / (white * (C * white + D) + E);

	return color_tonemapped / white_tonemapped;
}



vec3 agx_contrast_approx(vec3 x) {
	
	
	
	
	vec3 x2 = x * x;
	vec3 x4 = x2 * x2;
	return 0.021 * x + 4.0111 * x2 - 25.682 * x2 * x + 70.359 * x4 - 74.778 * x4 * x + 27.069 * x4 * x2;
}




vec3 tonemap_agx(vec3 color) {
	
	const mat3 srgb_to_rec2020_agx_inset_matrix = mat3(
			0.54490813676363087053, 0.14044005884001287035, 0.088827411851915368603,
			0.37377945959812267119, 0.75410959864013760045, 0.17887712465043811023,
			0.081384976686407536266, 0.10543358536857773485, 0.73224999956948382528);

	
	const mat3 agx_outset_rec2020_to_srgb_matrix = mat3(
			1.9645509602733325934, -0.29932243390911083839, -0.16436833806080403409,
			-0.85585845117807513559, 1.3264510741502356555, -0.23822464068860595117,
			-0.10886710826831608324, -0.027084020983874825605, 1.402665347143271889);

	
	
	
	const float min_ev = -12.4739311883324; 
	const float max_ev = 4.02606881166759; 

	
	
	
	
	
	
	
	
	
	
	
	
	
	color = max(color, 2e-10);

	
	color = srgb_to_rec2020_agx_inset_matrix * color;

	
	
	
	color = clamp(log2(color), min_ev, max_ev);
	color = (color - min_ev) / (max_ev - min_ev);

	
	color = agx_contrast_approx(color);

	
	color = pow(color, vec3(2.4));

	
	color = agx_outset_rec2020_to_srgb_matrix * color;

	
	
	
	return color;
}

vec3 linear_to_srgb(vec3 color) {
	
	color = clamp(color, vec3(0.0), vec3(1.0));
	const vec3 a = vec3(0.055f);
	return mix((vec3(1.0f) + a) * pow(color.rgb, vec3(1.0f / 2.4f)) - a, 12.92f * color.rgb, lessThan(color.rgb, vec3(0.0031308f)));
}

#define TONEMAPPER_LINEAR 0
#define TONEMAPPER_REINHARD 1
#define TONEMAPPER_FILMIC 2
#define TONEMAPPER_ACES 3
#define TONEMAPPER_AGX 4

vec3 apply_tonemapping(vec3 color, float white) { 
	
	
	if (params.tonemapper == TONEMAPPER_LINEAR) {
		return color;
	} else if (params.tonemapper == TONEMAPPER_REINHARD) {
		return tonemap_reinhard(max(vec3(0.0f), color), white);
	} else if (params.tonemapper == TONEMAPPER_FILMIC) {
		return tonemap_filmic(max(vec3(0.0f), color), white);
	} else if (params.tonemapper == TONEMAPPER_ACES) {
		return tonemap_aces(max(vec3(0.0f), color), white);
	} else { 
		return tonemap_agx(color);
	}
}

#ifdef USE_MULTIVIEW
vec3 gather_glow(sampler2DArray tex, vec2 uv) { 
#else
vec3 gather_glow(sampler2D tex, vec2 uv) { 
#endif 
	vec3 glow = vec3(0.0f);

	if (params.glow_levels[0] > 0.0001) {
		glow += GLOW_TEXTURE_SAMPLE(tex, uv, 0).rgb * params.glow_levels[0];
	}

	if (params.glow_levels[1] > 0.0001) {
		glow += GLOW_TEXTURE_SAMPLE(tex, uv, 1).rgb * params.glow_levels[1];
	}

	if (params.glow_levels[2] > 0.0001) {
		glow += GLOW_TEXTURE_SAMPLE(tex, uv, 2).rgb * params.glow_levels[2];
	}

	if (params.glow_levels[3] > 0.0001) {
		glow += GLOW_TEXTURE_SAMPLE(tex, uv, 3).rgb * params.glow_levels[3];
	}

	if (params.glow_levels[4] > 0.0001) {
		glow += GLOW_TEXTURE_SAMPLE(tex, uv, 4).rgb * params.glow_levels[4];
	}

	if (params.glow_levels[5] > 0.0001) {
		glow += GLOW_TEXTURE_SAMPLE(tex, uv, 5).rgb * params.glow_levels[5];
	}

	if (params.glow_levels[6] > 0.0001) {
		glow += GLOW_TEXTURE_SAMPLE(tex, uv, 6).rgb * params.glow_levels[6];
	}

	return glow;
}

#define GLOW_MODE_ADD 0
#define GLOW_MODE_SCREEN 1
#define GLOW_MODE_SOFTLIGHT 2
#define GLOW_MODE_REPLACE 3
#define GLOW_MODE_MIX 4

vec3 apply_glow(vec3 color, vec3 glow) { 
	if (params.glow_mode == GLOW_MODE_ADD) {
		return color + glow;
	} else if (params.glow_mode == GLOW_MODE_SCREEN) {
		
		glow.rgb = clamp(glow.rgb, vec3(0.0f), vec3(1.0f));
		return max((color + glow) - (color * glow), vec3(0.0));
	} else if (params.glow_mode == GLOW_MODE_SOFTLIGHT) {
		
		glow.rgb = clamp(glow.rgb, vec3(0.0f), vec3(1.0f));
		glow = glow * vec3(0.5f) + vec3(0.5f);

		color.r = (glow.r <= 0.5f) ? (color.r - (1.0f - 2.0f * glow.r) * color.r * (1.0f - color.r)) : (((glow.r > 0.5f) && (color.r <= 0.25f)) ? (color.r + (2.0f * glow.r - 1.0f) * (4.0f * color.r * (4.0f * color.r + 1.0f) * (color.r - 1.0f) + 7.0f * color.r)) : (color.r + (2.0f * glow.r - 1.0f) * (sqrt(color.r) - color.r)));
		color.g = (glow.g <= 0.5f) ? (color.g - (1.0f - 2.0f * glow.g) * color.g * (1.0f - color.g)) : (((glow.g > 0.5f) && (color.g <= 0.25f)) ? (color.g + (2.0f * glow.g - 1.0f) * (4.0f * color.g * (4.0f * color.g + 1.0f) * (color.g - 1.0f) + 7.0f * color.g)) : (color.g + (2.0f * glow.g - 1.0f) * (sqrt(color.g) - color.g)));
		color.b = (glow.b <= 0.5f) ? (color.b - (1.0f - 2.0f * glow.b) * color.b * (1.0f - color.b)) : (((glow.b > 0.5f) && (color.b <= 0.25f)) ? (color.b + (2.0f * glow.b - 1.0f) * (4.0f * color.b * (4.0f * color.b + 1.0f) * (color.b - 1.0f) + 7.0f * color.b)) : (color.b + (2.0f * glow.b - 1.0f) * (sqrt(color.b) - color.b)));
		return color;
	} else { 
		return glow;
	}
}

vec3 apply_bcs(vec3 color, vec3 bcs) {
	color = mix(vec3(0.0f), color, bcs.x);
	color = mix(vec3(0.5f), color, bcs.y);
	color = mix(vec3(dot(vec3(1.0f), color) * 0.33333f), color, bcs.z);

	return color;
}
#ifdef USE_1D_LUT
vec3 apply_color_correction(vec3 color) {
	color.r = texture(source_color_correction, vec2(color.r, 0.0f)).r;
	color.g = texture(source_color_correction, vec2(color.g, 0.0f)).g;
	color.b = texture(source_color_correction, vec2(color.b, 0.0f)).b;
	return color;
}
#else
vec3 apply_color_correction(vec3 color) {
	return textureLod(source_color_correction, color, 0.0).rgb;
}
#endif

#ifndef SUBPASS
vec3 do_fxaa(vec3 color, float exposure, vec2 uv_interp) {
	const float FXAA_REDUCE_MIN = (1.0 / 128.0);
	const float FXAA_REDUCE_MUL = (1.0 / 8.0);
	const float FXAA_SPAN_MAX = 8.0;

#ifdef USE_MULTIVIEW
	vec3 rgbNW = textureLod(source_color, vec3(uv_interp + vec2(-0.5, -0.5) * params.pixel_size, ViewIndex), 0.0).xyz * exposure * params.luminance_multiplier;
	vec3 rgbNE = textureLod(source_color, vec3(uv_interp + vec2(0.5, -0.5) * params.pixel_size, ViewIndex), 0.0).xyz * exposure * params.luminance_multiplier;
	vec3 rgbSW = textureLod(source_color, vec3(uv_interp + vec2(-0.5, 0.5) * params.pixel_size, ViewIndex), 0.0).xyz * exposure * params.luminance_multiplier;
	vec3 rgbSE = textureLod(source_color, vec3(uv_interp + vec2(0.5, 0.5) * params.pixel_size, ViewIndex), 0.0).xyz * exposure * params.luminance_multiplier;
#else
	vec3 rgbNW = textureLod(source_color, uv_interp + vec2(-0.5, -0.5) * params.pixel_size, 0.0).xyz * exposure * params.luminance_multiplier;
	vec3 rgbNE = textureLod(source_color, uv_interp + vec2(0.5, -0.5) * params.pixel_size, 0.0).xyz * exposure * params.luminance_multiplier;
	vec3 rgbSW = textureLod(source_color, uv_interp + vec2(-0.5, 0.5) * params.pixel_size, 0.0).xyz * exposure * params.luminance_multiplier;
	vec3 rgbSE = textureLod(source_color, uv_interp + vec2(0.5, 0.5) * params.pixel_size, 0.0).xyz * exposure * params.luminance_multiplier;
#endif
	vec3 rgbM = color;
	vec3 luma = vec3(0.299, 0.587, 0.114);
	float lumaNW = dot(rgbNW, luma);
	float lumaNE = dot(rgbNE, luma);
	float lumaSW = dot(rgbSW, luma);
	float lumaSE = dot(rgbSE, luma);
	float lumaM = dot(rgbM, luma);
	float lumaMin = min(lumaM, min(min(lumaNW, lumaNE), min(lumaSW, lumaSE)));
	float lumaMax = max(lumaM, max(max(lumaNW, lumaNE), max(lumaSW, lumaSE)));

	vec2 dir;
	dir.x = -((lumaNW + lumaNE) - (lumaSW + lumaSE));
	dir.y = ((lumaNW + lumaSW) - (lumaNE + lumaSE));

	float dirReduce = max((lumaNW + lumaNE + lumaSW + lumaSE) *
					(0.25 * FXAA_REDUCE_MUL),
			FXAA_REDUCE_MIN);

	float rcpDirMin = 1.0 / (min(abs(dir.x), abs(dir.y)) + dirReduce);
	dir = min(vec2(FXAA_SPAN_MAX, FXAA_SPAN_MAX),
				  max(vec2(-FXAA_SPAN_MAX, -FXAA_SPAN_MAX),
						  dir * rcpDirMin)) *
			params.pixel_size;

#ifdef USE_MULTIVIEW
	vec3 rgbA = 0.5 * exposure * (textureLod(source_color, vec3(uv_interp + dir * (1.0 / 3.0 - 0.5), ViewIndex), 0.0).xyz + textureLod(source_color, vec3(uv_interp + dir * (2.0 / 3.0 - 0.5), ViewIndex), 0.0).xyz) * params.luminance_multiplier;
	vec3 rgbB = rgbA * 0.5 + 0.25 * exposure * (textureLod(source_color, vec3(uv_interp + dir * -0.5, ViewIndex), 0.0).xyz + textureLod(source_color, vec3(uv_interp + dir * 0.5, ViewIndex), 0.0).xyz) * params.luminance_multiplier;
#else
	vec3 rgbA = 0.5 * exposure * (textureLod(source_color, uv_interp + dir * (1.0 / 3.0 - 0.5), 0.0).xyz + textureLod(source_color, uv_interp + dir * (2.0 / 3.0 - 0.5), 0.0).xyz) * params.luminance_multiplier;
	vec3 rgbB = rgbA * 0.5 + 0.25 * exposure * (textureLod(source_color, uv_interp + dir * -0.5, 0.0).xyz + textureLod(source_color, uv_interp + dir * 0.5, 0.0).xyz) * params.luminance_multiplier;
#endif

	float lumaB = dot(rgbB, luma);
	if ((lumaB < lumaMin) || (lumaB > lumaMax)) {
		return rgbA;
	} else {
		return rgbB;
	}
}
#endif 




vec3 screen_space_dither(vec2 frag_coord) {
	
	vec3 dither = vec3(dot(vec2(171.0, 231.0), frag_coord));
	dither.rgb = fract(dither.rgb / vec3(103.0, 71.0, 97.0));

	
	return (dither.rgb - 0.5) / 255.0;
}

void main() {
#ifdef SUBPASS
	
	vec4 color = subpassLoad(input_color);
#elif defined(USE_MULTIVIEW)
	vec4 color = textureLod(source_color, vec3(uv_interp, ViewIndex), 0.0f);
#else
	vec4 color = textureLod(source_color, uv_interp, 0.0f);
#endif
	color.rgb *= params.luminance_multiplier;

	

	float exposure = params.exposure;

#ifndef SUBPASS
	if (bool(params.flags & FLAG_USE_AUTO_EXPOSURE)) {
		exposure *= 1.0 / (texelFetch(source_auto_exposure, ivec2(0, 0), 0).r * params.luminance_multiplier / params.auto_exposure_scale);
	}
#endif

	color.rgb *= exposure;

	
#ifndef SUBPASS
	if (bool(params.flags & FLAG_USE_FXAA)) {
		
		color.rgb = do_fxaa(color.rgb, exposure, uv_interp);
	}

	if (bool(params.flags & FLAG_USE_GLOW) && params.glow_mode == GLOW_MODE_MIX) {
		vec3 glow = gather_glow(source_glow, uv_interp) * params.luminance_multiplier;
		if (params.glow_map_strength > 0.001) {
			glow = mix(glow, texture(glow_map, uv_interp).rgb * glow, params.glow_map_strength);
		}
		color.rgb = mix(color.rgb, glow, params.glow_intensity);
	}
#endif

	color.rgb = apply_tonemapping(color.rgb, params.white);
)<!>" R"<!>(
	if (bool(params.flags & FLAG_CONVERT_TO_SRGB)) {
		color.rgb = linear_to_srgb(color.rgb); 
	}
#ifndef SUBPASS
	
	if (bool(params.flags & FLAG_USE_GLOW) && params.glow_mode != GLOW_MODE_MIX) {
		vec3 glow = gather_glow(source_glow, uv_interp) * params.glow_intensity * params.luminance_multiplier;
		if (params.glow_map_strength > 0.001) {
			glow = mix(glow, texture(glow_map, uv_interp).rgb * glow, params.glow_map_strength);
		}

		
		glow = apply_tonemapping(glow, params.white);
		if (bool(params.flags & FLAG_CONVERT_TO_SRGB)) {
			glow = linear_to_srgb(glow);
		}

		color.rgb = apply_glow(color.rgb, glow);
	}
#endif

	

	if (bool(params.flags & FLAG_USE_BCS)) {
		color.rgb = apply_bcs(color.rgb, params.bcs);
	}

	if (bool(params.flags & FLAG_USE_COLOR_CORRECTION)) {
		color.rgb = apply_color_correction(color.rgb);
	}

	if (bool(params.flags & FLAG_USE_DEBANDING)) {
		
		
		color.rgb += screen_space_dither(gl_FragCoord.xy);
	}

	frag_color = color;
}
)<!>"
		};
		setup(_vertex_code, _fragment_code, nullptr, "TonemapShaderRD");
	}
};

#endif
