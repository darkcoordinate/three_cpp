#ifndef THREE_MATERIAL_HPP
#define THREE_MATERIAL_HPP

#include <three/common.hpp>

#include <three/extras/noncopyable.hpp>

#include <three/materials/attribute.hpp>
#include <three/materials/custom_attribute.hpp>
#include <three/materials/program.hpp>
#include <three/materials/uniform.hpp>

#include <three/textures/texture.hpp>

namespace three {

class Material : public NonCopyable {
public:

	typedef std::shared_ptr<Material> Ptr;

	static Ptr create() { return make_shared<Material>( ); }

	virtual THREE::MaterialType type() const { return THREE::Material; }

	/////////////////////////////////////////////////////////////////////////

	int id;

	std::string name;

	CustomAttributes customAttributes;
	Attributes attributes;

	THREE::Side side;

	Color color, ambient, emissive, specular;
	float shininess;
	float opacity;
	bool transparent;

	float size;

	THREE::Shading shading;
	THREE::Colors vertexColors;

	THREE::Blending blending;
	THREE::BlendFactor blendSrc;
	THREE::BlendFactor blendDst;
	THREE::BlendEquation blendEquation;

	bool depthTest;
	bool depthWrite;

	bool polygonOffset;
	float polygonOffsetFactor;
	float polygonOffsetUnits;

	float alphaTest;

	bool overdraw; // Boolean for fixing antialiasing gaps in CanvasRenderer

	bool visible;

	bool needsUpdate;

	bool skinning;
	bool morphTargets;
	bool morphNormals;

	float reflectivity;
	float refractionRatio;
	THREE::TextureConstant combine;

	bool metal;
	bool perPixel;
	bool wrapAround;
	Vector3 wrapRGB;

	bool wireframe;
	float wireframeLinewidth;
	float linewidth;

	int numSupportedMorphTargets;
	int	numSupportedMorphNormals;

	Program::Ptr program;

	std::string fragmentShader;
	std::string vertexShader;
	Uniforms uniforms;

	UniformsList uniformsList;

	Texture::Ptr map, envMap, lightMap, bumpMap, specularMap;
	float bumpScale;

	bool fog;
	bool lights;
	bool shadowPass;
	float sizeAttenuation;

	/////////////////////////////////////////////////////////////////////////

	Material& clone ( Material& material ) {

		material.name                = name;

		material.side                = side;

		material.attributes          = material.attributes;
		material.customAttributes    = material.customAttributes;

		material.color               = color;
		material.ambient             = ambient;
		material.emissive            = emissive;
		material.specular            = specular;

		material.shininess           = shininess;
		material.opacity             = opacity;
		material.transparent         = transparent;

		material.size                = size;

		material.shading             = shading;

		material.vertexColors        = vertexColors;

		material.blending            = blending;

		material.blendSrc            = blendSrc;
		material.blendDst            = blendDst;
		material.blendEquation       = blendEquation;

		material.depthTest           = depthTest;
		material.depthWrite          = depthWrite;

		material.polygonOffset       = polygonOffset;
		material.polygonOffsetFactor = polygonOffsetFactor;
		material.polygonOffsetUnits  = polygonOffsetUnits;

		material.alphaTest           = alphaTest;

		material.overdraw            = overdraw;

		material.visible             = visible;

		material.skinning            = skinning;
		material.morphNormals        = morphNormals;
		material.morphTargets        = morphTargets;

		material.reflectivity        = reflectivity;
		material.refractionRatio     = refractionRatio;
		material.combine             = combine;

		material.metal               = metal;
		material.perPixel            = perPixel;
		material.wrapAround          = wrapAround;
		material.wrapRGB             = wrapRGB;

		material.wireframe           = wireframe;
		material.wireframeLinewidth  = wireframeLinewidth;
		material.linewidth           = linewidth;

		material.numSupportedMorphTargets = numSupportedMorphTargets;
		material.numSupportedMorphNormals = numSupportedMorphNormals;

		material.fragmentShader      = fragmentShader;
		material.vertexShader        = vertexShader;
		material.uniforms            = uniforms;

		material.map         = map;
		material.envMap      = envMap;
		material.lightMap    = lightMap;
		material.bumpMap     = bumpMap;
		material.specularMap = specularMap;

		material.bumpScale       = bumpScale;

		material.fog             = fog;
		material.lights          = lights;
		material.shadowPass      = shadowPass;
		material.sizeAttenuation = sizeAttenuation;

		return material;

	}

protected:

	Material ()
	: id ( MaterialCount()++ ),
	side ( THREE::FrontSide ),
	color ( 0xffffff ),
	ambient ( 0xffffff ),
	emissive ( 0x000000 ),
	specular ( 0x111111 ),
	shininess ( 30 ),
	opacity ( 1 ),
	transparent ( false ),
	size ( 1.f ),
	shading ( THREE::NoShading ),
	vertexColors ( THREE::NoColors ),
	blending ( THREE::NormalBlending ),
	blendSrc ( THREE::SrcAlphaFactor ),
	blendDst ( THREE::OneMinusSrcAlphaFactor ),
	blendEquation ( THREE::AddEquation ),
	depthTest ( true ),
	depthWrite ( true ),
	polygonOffset ( false ),
	polygonOffsetFactor ( 0 ),
	polygonOffsetUnits ( 0 ),
	alphaTest ( 0 ),
	overdraw ( false ),
	visible ( true ),
	needsUpdate ( true ),
	skinning ( false ),
	morphTargets ( false ),
	morphNormals ( false ),
	reflectivity ( 1.f ),
	refractionRatio ( 1.f ),
	combine ( THREE::MultiplyOperation ),
	metal ( false ),
	perPixel ( false ),
	wrapAround ( false ),
	wrapRGB ( 1, 1, 1 ),
	wireframe ( false ),
	wireframeLinewidth ( 1 ),
	linewidth ( 1 ),
	program	( 0 ),
	numSupportedMorphTargets ( 0 ),
	numSupportedMorphNormals ( 0 ),
	fog ( false ),
	lights ( false ),
	shadowPass ( false ),
	sizeAttenuation ( 0 ) { }

private:

	static int& MaterialCount() {
		static int sMaterialCount = 0;
		return sMaterialCount;
	}

};

} // namespace three

#endif // THREE_MATERIAL_HPP