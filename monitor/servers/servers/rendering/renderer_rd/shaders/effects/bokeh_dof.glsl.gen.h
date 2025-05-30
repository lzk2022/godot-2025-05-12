/* WARNING, THIS FILE WAS GENERATED, DO NOT EDIT */
#ifndef BOKEH_DOF_GLSL_GEN_H_RD
#define BOKEH_DOF_GLSL_GEN_H_RD

#include "servers/rendering/renderer_rd/shader_rd.h"

class BokehDofShaderRD : public ShaderRD {

public:

	BokehDofShaderRD() {

		static const char _compute_code[] = {
R"<!>(
#version 450

#VERSION_DEFINES

#define BLOCK_SIZE 8

layout(local_size_x = BLOCK_SIZE, local_size_y = BLOCK_SIZE, local_size_z = 1) in;

#ifdef MODE_GEN_BLUR_SIZE
layout(rgba16f, set = 0, binding = 0) uniform restrict image2D color_image;
layout(set = 1, binding = 0) uniform sampler2D source_depth;
#endif

#if defined(MODE_BOKEH_BOX) || defined(MODE_BOKEH_HEXAGONAL) || defined(MODE_BOKEH_CIRCULAR)
layout(set = 1, binding = 0) uniform sampler2D color_texture;
layout(rgba16f, set = 0, binding = 0) uniform restrict writeonly image2D bokeh_image;
#endif

#ifdef MODE_COMPOSITE_BOKEH
layout(rgba16f, set = 0, binding = 0) uniform restrict image2D color_image;
layout(set = 1, binding = 0) uniform sampler2D source_bokeh;
#endif



layout(push_constant, std430) uniform Params {
	ivec2 size;
	float z_far;
	float z_near;

	bool orthogonal;
	float blur_size;
	float blur_scale;
	int blur_steps;

	bool blur_near_active;
	float blur_near_begin;
	float blur_near_end;
	bool blur_far_active;

	float blur_far_begin;
	float blur_far_end;
	bool second_pass;
	bool half_size;

	bool use_jitter;
	float jitter_seed;
	bool use_physical_near;
	bool use_physical_far;

	float blur_size_near;
	float blur_size_far;
	uint pad[2];
}
params;


#define DEPTH_GAP 0.0

const float GOLDEN_ANGLE = 2.39996323;


float hash12n(vec2 p) {
	p = fract(p * vec2(5.3987, 5.4421));
	p += dot(p.yx, p.xy + vec2(21.5351, 14.3137));
	return fract(p.x * p.y * 95.4307);
}

#ifdef MODE_GEN_BLUR_SIZE

float get_depth_at_pos(vec2 uv) {
	float depth = textureLod(source_depth, uv, 0.0).x * 2.0 - 1.0;
	if (params.orthogonal) {
		depth = -(depth * (params.z_far - params.z_near) - (params.z_far + params.z_near)) / 2.0;
	} else {
		depth = 2.0 * params.z_near * params.z_far / (params.z_far + params.z_near + depth * (params.z_far - params.z_near));
	}
	return depth;
}

float get_blur_size(float depth) {
	if (params.blur_near_active && depth < params.blur_near_begin) {
		if (params.use_physical_near) {
			
			float d = abs(params.blur_near_begin - depth);
			return -(d / (params.blur_near_begin - d)) * params.blur_size_near - DEPTH_GAP; 
		} else {
			
			return -(1.0 - smoothstep(params.blur_near_end, params.blur_near_begin, depth)) * params.blur_size - DEPTH_GAP; 
		}
	}

	if (params.blur_far_active && depth > params.blur_far_begin) {
		if (params.use_physical_far) {
			
			float d = abs(params.blur_far_begin - depth);
			return (d / (params.blur_far_begin + d)) * params.blur_size_far + DEPTH_GAP;
		} else {
			
			return smoothstep(params.blur_far_begin, params.blur_far_end, depth) * params.blur_size + DEPTH_GAP;
		}
	}

	return 0.0;
}

#endif

#if defined(MODE_BOKEH_BOX) || defined(MODE_BOKEH_HEXAGONAL)

vec4 weighted_filter_dir(vec2 dir, vec2 uv, vec2 pixel_size) {
	dir *= pixel_size;
	vec4 color = texture(color_texture, uv);

	vec4 accum = color;
	float total = 1.0;

	float blur_scale = params.blur_size / float(params.blur_steps);

	if (params.use_jitter) {
		uv += dir * (hash12n(uv + params.jitter_seed) - 0.5);
	}

	for (int i = -params.blur_steps; i <= params.blur_steps; i++) {
		if (i == 0) {
			continue;
		}
		float radius = float(i) * blur_scale;
		vec2 suv = uv + dir * radius;
		radius = abs(radius);

		vec4 sample_color = texture(color_texture, suv);
		float limit;

		if (sample_color.a < color.a) {
			limit = abs(sample_color.a);
		} else {
			limit = abs(color.a);
		}

		limit -= DEPTH_GAP;

		float m = smoothstep(radius - 0.5, radius + 0.5, limit);

		accum += mix(color, sample_color, m);

		total += 1.0;
	}

	return accum / total;
}

#endif

void main() {
	ivec2 pos = ivec2(gl_GlobalInvocationID.xy);

	if (any(greaterThan(pos, params.size))) { 
		return;
	}

	vec2 pixel_size = 1.0 / vec2(params.size);
	vec2 uv = vec2(pos) / vec2(params.size);

#ifdef MODE_GEN_BLUR_SIZE
	uv += pixel_size * 0.5;
	
	float depth = get_depth_at_pos(uv);
	float size = get_blur_size(depth);

	vec4 color = imageLoad(color_image, pos);
	color.a = size;
	imageStore(color_image, pos, color);
#endif

#ifdef MODE_BOKEH_BOX

	
	if (params.second_pass || !params.half_size) {
		uv += pixel_size * 0.5; 
	} else {
		uv += pixel_size * 0.25; 
	}

	vec2 dir = (params.second_pass ? vec2(0.0, 1.0) : vec2(1.0, 0.0));

	vec4 color = weighted_filter_dir(dir, uv, pixel_size);

	imageStore(bokeh_image, pos, color);

#endif

#ifdef MODE_BOKEH_HEXAGONAL

	
	if (params.second_pass || !params.half_size) {
		uv += pixel_size * 0.5; 
	} else {
		uv += pixel_size * 0.25; 
	}

	vec2 dir = (params.second_pass ? normalize(vec2(1.0, 0.577350269189626)) : vec2(0.0, 1.0));

	vec4 color = weighted_filter_dir(dir, uv, pixel_size);

	if (params.second_pass) {
		dir = normalize(vec2(-1.0, 0.577350269189626));

		vec4 color2 = weighted_filter_dir(dir, uv, pixel_size);

		color.rgb = min(color.rgb, color2.rgb);
		color.a = (color.a + color2.a) * 0.5;
	}

	imageStore(bokeh_image, pos, color);

#endif

#ifdef MODE_BOKEH_CIRCULAR

	if (params.half_size) {
		pixel_size *= 0.5; 
	}

	uv += pixel_size * 0.5; 

	vec4 color = texture(color_texture, uv);
	float initial_blur = color.a;
	float accum = 1.0;
	float radius = params.blur_scale;

	for (float ang = 0.0; radius < params.blur_size; ang += GOLDEN_ANGLE) {
		vec2 suv = uv + vec2(cos(ang), sin(ang)) * pixel_size * radius;
		vec4 sample_color = texture(color_texture, suv);
		float sample_size = abs(sample_color.a);
		if (sample_color.a > initial_blur) {
			sample_size = clamp(sample_size, 0.0, abs(initial_blur) * 2.0);
		}

		float m = smoothstep(radius - 0.5, radius + 0.5, sample_size);
		color += mix(color / accum, sample_color, m);
		accum += 1.0;
		radius += params.blur_scale / radius;
	}

	color /= accum;

	imageStore(bokeh_image, pos, color);
#endif

#ifdef MODE_COMPOSITE_BOKEH

	uv += pixel_size * 0.5;
	vec4 color = imageLoad(color_image, pos);
	vec4 bokeh = texture(source_bokeh, uv);

	float mix_amount;
	if (bokeh.a < color.a) {
		mix_amount = min(1.0, max(0.0, max(abs(color.a), abs(bokeh.a)) - DEPTH_GAP));
	} else {
		mix_amount = min(1.0, max(0.0, abs(color.a) - DEPTH_GAP));
	}

	color.rgb = mix(color.rgb, bokeh.rgb, mix_amount); 

	color.a = 0; 
	imageStore(color_image, pos, color);
#endif
}
)<!>"
		};
		setup(nullptr, nullptr, _compute_code, "BokehDofShaderRD");
	}
};

#endif
