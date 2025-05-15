/* WARNING, THIS FILE WAS GENERATED, DO NOT EDIT */
#ifndef MOTION_VECTORS_STORE_GLSL_GEN_H_RD
#define MOTION_VECTORS_STORE_GLSL_GEN_H_RD

#include "servers/rendering/renderer_rd/shader_rd.h"

class MotionVectorsStoreShaderRD : public ShaderRD {

public:

	MotionVectorsStoreShaderRD() {

		static const char _compute_code[] = {
R"<!>(
#version 450

#VERSION_DEFINES

vec2 derive_motion_vector(vec2 uv, float depth, mat4 reprojection_matrix) {
	vec4 previous_pos_ndc = reprojection_matrix * vec4(uv * 2.0f - 1.0f, depth * 2.0f - 1.0f, 1.0f);
	return 0.5f + (previous_pos_ndc.xy / previous_pos_ndc.w) * 0.5f - uv;
}

#define FFX_FSR2_OPTION_GODOT_DERIVE_INVALID_MOTION_VECTORS_FUNCTION(i, j, k) derive_motion_vector(i, j, k)

layout(local_size_x = 8, local_size_y = 8, local_size_z = 1) in;
layout(set = 0, binding = 0) uniform sampler2D depth_buffer;
layout(rg16f, set = 0, binding = 1) uniform restrict writeonly image2D velocity_buffer;

layout(push_constant, std430) uniform Params {
	highp mat4 reprojection_matrix;
	vec2 resolution;
	uint pad[2];
}
params;

void main() {
	
	if (any(greaterThanEqual(vec2(gl_GlobalInvocationID.xy), params.resolution))) {
		return;
	}

	ivec2 pos = ivec2(gl_GlobalInvocationID.xy);

	float depth = texelFetch(depth_buffer, pos, 0).x;
	vec2 uv = (vec2(pos) + 0.5f) / params.resolution;
	vec2 velocity = derive_motion_vector(uv, depth, params.reprojection_matrix);
	imageStore(velocity_buffer, pos, vec4(velocity, 0.0f, 0.0f));
}
)<!>"
		};
		setup(nullptr, nullptr, _compute_code, "MotionVectorsStoreShaderRD");
	}
};

#endif
