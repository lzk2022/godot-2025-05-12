/* WARNING, THIS FILE WAS GENERATED, DO NOT EDIT */
#ifndef SKY_GLSL_GEN_H_RD
#define SKY_GLSL_GEN_H_RD

#include "servers/rendering/renderer_rd/shader_rd.h"

class SkyShaderRD : public ShaderRD {

public:

	SkyShaderRD() {

		static const char _vertex_code[] = {
R"<!>(
#version 450

#VERSION_DEFINES

#define MAX_VIEWS 2

#if defined(USE_MULTIVIEW) && defined(has_VK_KHR_multiview)
#extension GL_EXT_multiview : enable
#endif

layout(location = 0) out vec2 uv_interp;

layout(push_constant, std430) uniform Params {
	mat3 orientation;
	vec4 projection; 
	vec3 position;
	float time;
	vec2 pad;
	float luminance_multiplier;
	float brightness_multiplier;
}
params;

void main() {
	vec2 base_arr[3] = vec2[](vec2(-1.0, -3.0), vec2(-1.0, 1.0), vec2(3.0, 1.0));
	uv_interp = base_arr[gl_VertexIndex];
	gl_Position = vec4(uv_interp, 0.0, 1.0);
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
#else 

#define ViewIndex 0
#endif 

#define M_PI 3.14159265359
#define MAX_VIEWS 2

layout(location = 0) in vec2 uv_interp;

layout(push_constant, std430) uniform Params {
	mat3 orientation;
	vec4 projection; 
	vec3 position;
	float time;
	vec2 pad;
	float luminance_multiplier;
	float brightness_multiplier;
}
params;

layout(set = 0, binding = SAMPLERS_BINDING_FIRST_INDEX + 0) uniform sampler SAMPLER_NEAREST_CLAMP;
layout(set = 0, binding = SAMPLERS_BINDING_FIRST_INDEX + 1) uniform sampler SAMPLER_LINEAR_CLAMP;
layout(set = 0, binding = SAMPLERS_BINDING_FIRST_INDEX + 2) uniform sampler SAMPLER_NEAREST_WITH_MIPMAPS_CLAMP;
layout(set = 0, binding = SAMPLERS_BINDING_FIRST_INDEX + 3) uniform sampler SAMPLER_LINEAR_WITH_MIPMAPS_CLAMP;
layout(set = 0, binding = SAMPLERS_BINDING_FIRST_INDEX + 4) uniform sampler SAMPLER_NEAREST_WITH_MIPMAPS_ANISOTROPIC_CLAMP;
layout(set = 0, binding = SAMPLERS_BINDING_FIRST_INDEX + 5) uniform sampler SAMPLER_LINEAR_WITH_MIPMAPS_ANISOTROPIC_CLAMP;
layout(set = 0, binding = SAMPLERS_BINDING_FIRST_INDEX + 6) uniform sampler SAMPLER_NEAREST_REPEAT;
layout(set = 0, binding = SAMPLERS_BINDING_FIRST_INDEX + 7) uniform sampler SAMPLER_LINEAR_REPEAT;
layout(set = 0, binding = SAMPLERS_BINDING_FIRST_INDEX + 8) uniform sampler SAMPLER_NEAREST_WITH_MIPMAPS_REPEAT;
layout(set = 0, binding = SAMPLERS_BINDING_FIRST_INDEX + 9) uniform sampler SAMPLER_LINEAR_WITH_MIPMAPS_REPEAT;
layout(set = 0, binding = SAMPLERS_BINDING_FIRST_INDEX + 10) uniform sampler SAMPLER_NEAREST_WITH_MIPMAPS_ANISOTROPIC_REPEAT;
layout(set = 0, binding = SAMPLERS_BINDING_FIRST_INDEX + 11) uniform sampler SAMPLER_LINEAR_WITH_MIPMAPS_ANISOTROPIC_REPEAT;

layout(set = 0, binding = 1, std430) restrict readonly buffer GlobalShaderUniformData {
	vec4 data[];
}
global_shader_uniforms;

layout(set = 0, binding = 2, std140) uniform SkySceneData {
	mat4 combined_reprojection[2];
	mat4 view_inv_projections[2];
	vec4 view_eye_offsets[2];

	bool volumetric_fog_enabled; 
	float volumetric_fog_inv_length; 
	float volumetric_fog_detail_spread; 
	float volumetric_fog_sky_affect; 

	bool fog_enabled; 
	float fog_sky_affect; 
	float fog_density; 
	float fog_sun_scatter; 

	vec3 fog_light_color; 
	float fog_aerial_perspective; 

	float z_far; 
	uint directional_light_count; 
	uint pad1; 
	uint pad2; 
}
sky_scene_data;

struct DirectionalLightData {
	vec4 direction_energy;
	vec4 color_size;
	bool enabled;
};

layout(set = 0, binding = 3, std140) uniform DirectionalLights {
	DirectionalLightData data[MAX_DIRECTIONAL_LIGHT_DATA_STRUCTS];
}
directional_lights;

#ifdef MATERIAL_UNIFORMS_USED
/* clang-format off */
layout(set = 1, binding = 0, std140) uniform MaterialUniforms {
#MATERIAL_UNIFORMS
} material;
/* clang-format on */
#endif

layout(set = 2, binding = 0) uniform textureCube radiance;
#ifdef USE_CUBEMAP_PASS
layout(set = 2, binding = 1) uniform textureCube half_res;
layout(set = 2, binding = 2) uniform textureCube quarter_res;
#elif defined(USE_MULTIVIEW)
layout(set = 2, binding = 1) uniform texture2DArray half_res;
layout(set = 2, binding = 2) uniform texture2DArray quarter_res;
#else
layout(set = 2, binding = 1) uniform texture2D half_res;
layout(set = 2, binding = 2) uniform texture2D quarter_res;
#endif

layout(set = 3, binding = 0) uniform texture3D volumetric_fog_texture;

#ifdef USE_CUBEMAP_PASS
#define AT_CUBEMAP_PASS true
#else
#define AT_CUBEMAP_PASS false
#endif

#ifdef USE_HALF_RES_PASS
#define AT_HALF_RES_PASS true
#else
#define AT_HALF_RES_PASS false
#endif

#ifdef USE_QUARTER_RES_PASS
#define AT_QUARTER_RES_PASS true
#else
#define AT_QUARTER_RES_PASS false
#endif

#GLOBALS

layout(location = 0) out vec4 frag_color;

#ifdef USE_DEBANDING

vec3 interleaved_gradient_noise(vec2 pos) {
	const vec3 magic = vec3(0.06711056f, 0.00583715f, 52.9829189f);
	float res = fract(magic.z * fract(dot(pos, magic.xy))) * 2.0 - 1.0;
	return vec3(res, -res, res) / 255.0;
}
#endif

vec4 volumetric_fog_process(vec2 screen_uv) {
#ifdef USE_MULTIVIEW
	vec4 reprojected = sky_scene_data.combined_reprojection[ViewIndex] * vec4(screen_uv * 2.0 - 1.0, 0.0, 1.0); 
	vec3 fog_pos = vec3(reprojected.xy / reprojected.w, 1.0) * 0.5 + 0.5;
#else
	vec3 fog_pos = vec3(screen_uv, 1.0);
#endif

	return texture(sampler3D(volumetric_fog_texture, SAMPLER_LINEAR_CLAMP), fog_pos);
}

vec4 fog_process(vec3 view, vec3 sky_color) {
	vec3 fog_color = mix(sky_scene_data.fog_light_color, sky_color, sky_scene_data.fog_aerial_perspective);

	if (sky_scene_data.fog_sun_scatter > 0.001) {
		vec4 sun_scatter = vec4(0.0);
		float sun_total = 0.0;
		for (uint i = 0; i < sky_scene_data.directional_light_count; i++) {
			vec3 light_color = directional_lights.data[i].color_size.xyz * directional_lights.data[i].direction_energy.w;
			float light_amount = pow(max(dot(view, directional_lights.data[i].direction_energy.xyz), 0.0), 8.0);
			fog_color += light_color * light_amount * sky_scene_data.fog_sun_scatter;
		}
	}

	return vec4(fog_color, 1.0);
}

void main() {
	vec3 cube_normal;
#ifdef USE_MULTIVIEW
	
	vec4 unproject = vec4(uv_interp.x, uv_interp.y, 0.0, 1.0); 
	vec4 unprojected = sky_scene_data.view_inv_projections[ViewIndex] * unproject;
	cube_normal = unprojected.xyz / unprojected.w;

	
	cube_normal += sky_scene_data.view_eye_offsets[ViewIndex].xyz;
#else
	cube_normal.z = -1.0;
	cube_normal.x = (cube_normal.z * (-uv_interp.x - params.projection.x)) / params.projection.y;
	cube_normal.y = -(cube_normal.z * (uv_interp.y - params.projection.z)) / params.projection.w;
#endif
	cube_normal = mat3(params.orientation) * cube_normal;
	cube_normal = normalize(cube_normal);

	vec2 uv = uv_interp * 0.5 + 0.5;

	vec2 panorama_coords = vec2(atan(cube_normal.x, -cube_normal.z), acos(cube_normal.y));

	if (panorama_coords.x < 0.0) {
		panorama_coords.x += M_PI * 2.0;
	}

	panorama_coords /= vec2(M_PI * 2.0, M_PI);

	vec3 color = vec3(0.0, 0.0, 0.0);
	float alpha = 1.0; 
	vec4 half_res_color = vec4(1.0);
	vec4 quarter_res_color = vec4(1.0);
	vec4 custom_fog = vec4(0.0);

#ifdef USE_CUBEMAP_PASS

#ifdef USES_HALF_RES_COLOR
	half_res_color = texture(samplerCube(half_res, SAMPLER_LINEAR_WITH_MIPMAPS_CLAMP), cube_normal) / params.luminance_multiplier;
#endif
#ifdef USES_QUARTER_RES_COLOR
	quarter_res_color = texture(samplerCube(quarter_res, SAMPLER_LINEAR_WITH_MIPMAPS_CLAMP), cube_normal) / params.luminance_multiplier;
#endif

#else

#ifdef USES_HALF_RES_COLOR
#ifdef USE_MULTIVIEW
	half_res_color = textureLod(sampler2DArray(half_res, SAMPLER_LINEAR_CLAMP), vec3(uv, ViewIndex), 0.0) / params.luminance_multiplier;
#else
	half_res_color = textureLod(sampler2D(half_res, SAMPLER_LINEAR_CLAMP), uv, 0.0) / params.luminance_multiplier;
#endif 
#endif 

#ifdef USES_QUARTER_RES_COLOR
#ifdef USE_MULTIVIEW
	quarter_res_color = textureLod(sampler2DArray(quarter_res, SAMPLER_LINEAR_CLAMP), vec3(uv, ViewIndex), 0.0) / params.luminance_multiplier;
#else
	quarter_res_color = textureLod(sampler2D(quarter_res, SAMPLER_LINEAR_CLAMP), uv, 0.0) / params.luminance_multiplier;
#endif 
#endif 

#endif 

	{
#CODE : SKY
	}

	frag_color.rgb = color;
	frag_color.a = alpha;

	
	frag_color.rgb = frag_color.rgb * params.brightness_multiplier;

#if !defined(DISABLE_FOG) && !defined(USE_CUBEMAP_PASS)

	
	if (sky_scene_data.fog_enabled) {
		vec4 fog = fog_process(cube_normal, frag_color.rgb);
		frag_color.rgb = mix(frag_color.rgb, fog.rgb, fog.a * sky_scene_data.fog_sky_affect);
	}

	if (sky_scene_data.volumetric_fog_enabled) {
		vec4 fog = volumetric_fog_process(uv);
		frag_color.rgb = mix(frag_color.rgb, fog.rgb, fog.a * sky_scene_data.volumetric_fog_sky_affect);
	}

	if (custom_fog.a > 0.0) {
		frag_color.rgb = mix(frag_color.rgb, custom_fog.rgb, custom_fog.a);
	}

#endif 

	
	
	frag_color.rgb = frag_color.rgb * params.luminance_multiplier;

	
	
	if (!AT_CUBEMAP_PASS && !AT_HALF_RES_PASS && !AT_QUARTER_RES_PASS) {
		frag_color.a = 0.0;
	}

#ifdef USE_DEBANDING
	frag_color.rgb += interleaved_gradient_noise(gl_FragCoord.xy) * params.luminance_multiplier;
#endif
}
)<!>"
		};
		setup(_vertex_code, _fragment_code, nullptr, "SkyShaderRD");
	}
};

#endif
