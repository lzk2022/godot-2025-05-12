/* WARNING, THIS FILE WAS GENERATED, DO NOT EDIT */
#ifndef CUBE_TO_DP_GLSL_GEN_H_RD
#define CUBE_TO_DP_GLSL_GEN_H_RD

#include "servers/rendering/renderer_rd/shader_rd.h"

class CubeToDpShaderRD : public ShaderRD {

public:

	CubeToDpShaderRD() {

		static const char _vertex_code[] = {
R"<!>(
#version 450

#VERSION_DEFINES

layout(push_constant, std430) uniform Params {
	float z_far;
	float z_near;
	vec2 texel_size;
}
params;

layout(location = 0) out vec2 uv_interp;

void main() {
	vec2 base_arr[4] = vec2[](vec2(0.0, 0.0), vec2(0.0, 1.0), vec2(1.0, 1.0), vec2(1.0, 0.0));
	uv_interp = base_arr[gl_VertexIndex];
	gl_Position = vec4(uv_interp * 2.0 - 1.0, 0.0, 1.0);
}

)<!>"
		};
		static const char _fragment_code[] = {
R"<!>(
#version 450

#VERSION_DEFINES

layout(location = 0) in vec2 uv_interp;

layout(set = 0, binding = 0) uniform samplerCube source_cube;

layout(push_constant, std430) uniform Params {
	float z_far;
	float z_near;
	vec2 texel_size;
}
params;

void main() {
	vec2 uv = uv_interp;
	vec2 texel_size = abs(params.texel_size);

	uv = clamp(uv * (1.0 + 2.0 * texel_size) - texel_size, vec2(0.0), vec2(1.0));

	vec3 normal = vec3(uv * 2.0 - 1.0, 0.0);
	normal.z = 0.5 * (1.0 - dot(normal.xy, normal.xy)); 
	normal = normalize(normal);

	normal.y = -normal.y; 
	if (params.texel_size.x >= 0.0) { 
		normal.z = -normal.z;
	}

	float depth = texture(source_cube, normal).r;

	
	vec3 unorm = abs(normal);

	if ((unorm.x >= unorm.y) && (unorm.x >= unorm.z)) {
		
		unorm = normal.x > 0.0 ? vec3(1.0, 0.0, 0.0) : vec3(-1.0, 0.0, 0.0);
	} else if ((unorm.y > unorm.x) && (unorm.y >= unorm.z)) {
		
		unorm = normal.y > 0.0 ? vec3(0.0, 1.0, 0.0) : vec3(0.0, -1.0, 0.0);
	} else if ((unorm.z > unorm.x) && (unorm.z > unorm.y)) {
		
		unorm = normal.z > 0.0 ? vec3(0.0, 0.0, 1.0) : vec3(0.0, 0.0, -1.0);
	} else {
		
		
		unorm = vec3(1.0, 0.0, 0.0);
	}

	float depth_fix = 1.0 / dot(normal, unorm);

	depth = 2.0 * depth - 1.0;
	float linear_depth = 2.0 * params.z_near * params.z_far / (params.z_far + params.z_near + depth * (params.z_far - params.z_near));
	
	depth = (params.z_far - linear_depth * depth_fix) / params.z_far;
	gl_FragDepth = depth;
}
)<!>"
		};
		setup(_vertex_code, _fragment_code, nullptr, "CubeToDpShaderRD");
	}
};

#endif
