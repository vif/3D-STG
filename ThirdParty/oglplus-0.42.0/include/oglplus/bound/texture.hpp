
/**
 *  @file oglplus/bound/texture.hpp
 *  @brief Specialization of BoundTemplate for Texture.
 *
 *  Automatically generated file, do not edit manually!
 *
 *  Copyright 2010-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */


#ifndef OGLPLUS_BOUND_TEXTURE_1107121519_HPP
#define OGLPLUS_BOUND_TEXTURE_1107121519_HPP

#include <oglplus/texture.hpp>
#include <oglplus/bound.hpp>
#include <oglplus/auto_bind.hpp>
#include <utility>

namespace oglplus {

/// Specialization of the BoundTemplate for TextureOps, implements Bound < Texture  >.
/** This template implements wrappers around the member functions
 *  of Texture, which have
 *  a TextureOps::Target parameter
 *  specifying the binding point on which they should operate.
 *
 *  @note Do not use this template class directly use
 *  Bound < Texture > or the Bind()
 *  function instead.
 *
 *  @see Bind()
 *  @see Bound
 *  @see AutoBind
 *
 *  @ingroup utility_classes
 */
template <template <class, class> class Base, class BaseParam>
class BoundTemplate<Base, BaseParam, TextureOps>
 : public Base<BaseParam, TextureOps>
{
private:
	typedef Base<
		BaseParam,
		TextureOps
	> _base;
public:
	BoundTemplate(
		const TextureOps& bindable,
		TextureOps::Target target
	): _base(bindable, target)
	{ }

	BoundTemplate(
		TextureOps::Target target
	): _base(target)
	{ }


	BoundTemplate(
		const TextureOps& bindable,
		TextureOps::Target target,
		GLuint tex_unit
	): _base(bindable, target, tex_unit)
	{ }

	BoundTemplate(
		TextureOps::Target target,
		GLuint tex_unit
	): _base(target, tex_unit)
	{ }


	/** Wrapper for Texture::GetIntParam()
	 *  @see Texture::GetIntParam()
	 */
	GLint GetIntParam(
		GLenum query
	) const
	{
		return TextureOps::GetIntParam(
			this->BindTarget(),
			query
		);
	}


	/** Wrapper for Texture::GetFloatParam()
	 *  @see Texture::GetFloatParam()
	 */
	GLfloat GetFloatParam(
		GLenum query
	) const
	{
		return TextureOps::GetFloatParam(
			this->BindTarget(),
			query
		);
	}


	/** Wrapper for Texture::GetIntParam()
	 *  @see Texture::GetIntParam()
	 */
	GLint GetIntParam(
		GLint level,
		GLenum query
	) const
	{
		return TextureOps::GetIntParam(
			this->BindTarget(),
			level,
			query
		);
	}


	/** Wrapper for Texture::GetFloatParam()
	 *  @see Texture::GetFloatParam()
	 */
	GLfloat GetFloatParam(
		GLint level,
		GLenum query
	) const
	{
		return TextureOps::GetFloatParam(
			this->BindTarget(),
			level,
			query
		);
	}


	/** Wrapper for Texture::Width()
	 *  @see Texture::Width()
	 */
	GLsizei Width(
		GLint level = 0
	) const
	{
		return TextureOps::Width(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::Height()
	 *  @see Texture::Height()
	 */
	GLsizei Height(
		GLint level = 0
	) const
	{
		return TextureOps::Height(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::Depth()
	 *  @see Texture::Depth()
	 */
	GLsizei Depth(
		GLint level = 0
	) const
	{
		return TextureOps::Depth(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::RedType()
	 *  @see Texture::RedType()
	 */
	PixelDataType RedType(
		GLint level = 0
	) const
	{
		return TextureOps::RedType(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::GreenType()
	 *  @see Texture::GreenType()
	 */
	PixelDataType GreenType(
		GLint level = 0
	) const
	{
		return TextureOps::GreenType(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::BlueType()
	 *  @see Texture::BlueType()
	 */
	PixelDataType BlueType(
		GLint level = 0
	) const
	{
		return TextureOps::BlueType(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::AlphaType()
	 *  @see Texture::AlphaType()
	 */
	PixelDataType AlphaType(
		GLint level = 0
	) const
	{
		return TextureOps::AlphaType(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::DepthType()
	 *  @see Texture::DepthType()
	 */
	PixelDataType DepthType(
		GLint level = 0
	) const
	{
		return TextureOps::DepthType(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::RedSize()
	 *  @see Texture::RedSize()
	 */
	GLsizei RedSize(
		GLint level = 0
	) const
	{
		return TextureOps::RedSize(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::GreenSize()
	 *  @see Texture::GreenSize()
	 */
	GLsizei GreenSize(
		GLint level = 0
	) const
	{
		return TextureOps::GreenSize(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::BlueSize()
	 *  @see Texture::BlueSize()
	 */
	GLsizei BlueSize(
		GLint level = 0
	) const
	{
		return TextureOps::BlueSize(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::AlphaSize()
	 *  @see Texture::AlphaSize()
	 */
	GLsizei AlphaSize(
		GLint level = 0
	) const
	{
		return TextureOps::AlphaSize(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::DepthSize()
	 *  @see Texture::DepthSize()
	 */
	GLsizei DepthSize(
		GLint level = 0
	) const
	{
		return TextureOps::DepthSize(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::StencilSize()
	 *  @see Texture::StencilSize()
	 */
	GLsizei StencilSize(
		GLint level = 0
	) const
	{
		return TextureOps::StencilSize(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::SharedSize()
	 *  @see Texture::SharedSize()
	 */
	GLsizei SharedSize(
		GLint level = 0
	) const
	{
		return TextureOps::SharedSize(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::CompressedImageSize()
	 *  @see Texture::CompressedImageSize()
	 */
	GLsizei CompressedImageSize(
		GLint level = 0
	) const
	{
		return TextureOps::CompressedImageSize(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::InternalFormat()
	 *  @see Texture::InternalFormat()
	 */
	PixelDataInternalFormat InternalFormat(
		GLint level = 0
	) const
	{
		return TextureOps::InternalFormat(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::GetImage()
	 *  @see Texture::GetImage()
	 */
	void GetImage(
		GLint level,
		PixelDataFormat format,
		TextureOps::Property::PixDataType type,
		GLsizei size,
		GLvoid * buffer
	) const
	{
		TextureOps::GetImage(
			this->BindTarget(),
			level,
			format,
			type,
			size,
			buffer
		);
	}


	/** Wrapper for Texture::GetImage()
	 *  @see Texture::GetImage()
	 */
	template <typename T>
	void GetImage(
		GLint level,
		PixelDataFormat format,
		std::vector< T > & dest
	) const
	{
		TextureOps::GetImage(
			this->BindTarget(),
			level,
			format,
			dest
		);
	}


	/** Wrapper for Texture::GetCompressedImage()
	 *  @see Texture::GetCompressedImage()
	 */
	void GetCompressedImage(
		GLint level,
		GLsizei size,
		GLubyte * buffer
	) const
	{
		TextureOps::GetCompressedImage(
			this->BindTarget(),
			level,
			size,
			buffer
		);
	}


	/** Wrapper for Texture::GetCompressedImage()
	 *  @see Texture::GetCompressedImage()
	 */
	void GetCompressedImage(
		GLint level,
		std::vector< GLubyte > & dest
	) const
	{
		TextureOps::GetCompressedImage(
			this->BindTarget(),
			level,
			dest
		);
	}


	/** Wrapper for Texture::Image3D()
	 *  @see Texture::Image3D()
	 */
	void Image3D(
		GLint level,
		PixelDataInternalFormat internal_format,
		GLsizei width,
		GLsizei height,
		GLsizei depth,
		GLint border,
		PixelDataFormat format,
		TextureOps::Property::PixDataType type,
		const void * data
	) const
	{
		TextureOps::Image3D(
			this->BindTarget(),
			level,
			internal_format,
			width,
			height,
			depth,
			border,
			format,
			type,
			data
		);
	}


	/** Wrapper for Texture::Image3D()
	 *  @see Texture::Image3D()
	 */
	void Image3D(
		const images::Image & image,
		GLint level = 0,
		GLint border = 0
	) const
	{
		TextureOps::Image3D(
			this->BindTarget(),
			image,
			level,
			border
		);
	}


	/** Wrapper for Texture::SubImage3D()
	 *  @see Texture::SubImage3D()
	 */
	void SubImage3D(
		GLint level,
		GLint xoffs,
		GLint yoffs,
		GLint zoffs,
		GLsizei width,
		GLsizei height,
		GLsizei depth,
		PixelDataFormat format,
		TextureOps::Property::PixDataType type,
		const void * data
	) const
	{
		TextureOps::SubImage3D(
			this->BindTarget(),
			level,
			xoffs,
			yoffs,
			zoffs,
			width,
			height,
			depth,
			format,
			type,
			data
		);
	}


	/** Wrapper for Texture::SubImage3D()
	 *  @see Texture::SubImage3D()
	 */
	void SubImage3D(
		const images::Image & image,
		GLint xoffs,
		GLint yoffs,
		GLint zoffs,
		GLint level = 0
	) const
	{
		TextureOps::SubImage3D(
			this->BindTarget(),
			image,
			xoffs,
			yoffs,
			zoffs,
			level
		);
	}


	/** Wrapper for Texture::Image2D()
	 *  @see Texture::Image2D()
	 */
	void Image2D(
		GLint level,
		PixelDataInternalFormat internal_format,
		GLsizei width,
		GLsizei height,
		GLint border,
		PixelDataFormat format,
		TextureOps::Property::PixDataType type,
		const void * data
	) const
	{
		TextureOps::Image2D(
			this->BindTarget(),
			level,
			internal_format,
			width,
			height,
			border,
			format,
			type,
			data
		);
	}


	/** Wrapper for Texture::Image2D()
	 *  @see Texture::Image2D()
	 */
	void Image2D(
		const images::Image & image,
		GLint level = 0,
		GLint border = 0
	) const
	{
		TextureOps::Image2D(
			this->BindTarget(),
			image,
			level,
			border
		);
	}


	/** Wrapper for Texture::SubImage2D()
	 *  @see Texture::SubImage2D()
	 */
	void SubImage2D(
		GLint level,
		GLint xoffs,
		GLint yoffs,
		GLsizei width,
		GLsizei height,
		PixelDataFormat format,
		TextureOps::Property::PixDataType type,
		const void * data
	) const
	{
		TextureOps::SubImage2D(
			this->BindTarget(),
			level,
			xoffs,
			yoffs,
			width,
			height,
			format,
			type,
			data
		);
	}


	/** Wrapper for Texture::SubImage2D()
	 *  @see Texture::SubImage2D()
	 */
	void SubImage2D(
		const images::Image & image,
		GLint xoffs,
		GLint yoffs,
		GLint level = 0
	) const
	{
		TextureOps::SubImage2D(
			this->BindTarget(),
			image,
			xoffs,
			yoffs,
			level
		);
	}


	/** Wrapper for Texture::Image1D()
	 *  @see Texture::Image1D()
	 */
	void Image1D(
		GLint level,
		PixelDataInternalFormat internal_format,
		GLsizei width,
		GLint border,
		PixelDataFormat format,
		TextureOps::Property::PixDataType type,
		const void * data
	) const
	{
		TextureOps::Image1D(
			this->BindTarget(),
			level,
			internal_format,
			width,
			border,
			format,
			type,
			data
		);
	}


	/** Wrapper for Texture::Image1D()
	 *  @see Texture::Image1D()
	 */
	void Image1D(
		const images::Image & image,
		GLint level = 0,
		GLint border = 0
	) const
	{
		TextureOps::Image1D(
			this->BindTarget(),
			image,
			level,
			border
		);
	}


	/** Wrapper for Texture::SubImage1D()
	 *  @see Texture::SubImage1D()
	 */
	void SubImage1D(
		GLint level,
		GLint xoffs,
		GLsizei width,
		PixelDataFormat format,
		TextureOps::Property::PixDataType type,
		const void * data
	) const
	{
		TextureOps::SubImage1D(
			this->BindTarget(),
			level,
			xoffs,
			width,
			format,
			type,
			data
		);
	}


	/** Wrapper for Texture::SubImage1D()
	 *  @see Texture::SubImage1D()
	 */
	void SubImage1D(
		const images::Image & image,
		GLint xoffs,
		GLint level = 0
	) const
	{
		TextureOps::SubImage1D(
			this->BindTarget(),
			image,
			xoffs,
			level
		);
	}


	/** Wrapper for Texture::Image()
	 *  @see Texture::Image()
	 */
	void Image(
		const images::Image & image,
		GLint level = 0,
		GLint border = 0
	) const
	{
		TextureOps::Image(
			this->BindTarget(),
			image,
			level,
			border
		);
	}


	/** Wrapper for Texture::Image()
	 *  @see Texture::Image()
	 */
	void Image(
		const images::ImageSpec & image_spec,
		GLint level = 0,
		GLint border = 0
	) const
	{
		TextureOps::Image(
			this->BindTarget(),
			image_spec,
			level,
			border
		);
	}


	/** Wrapper for Texture::CopyImage2D()
	 *  @see Texture::CopyImage2D()
	 */
	void CopyImage2D(
		GLint level,
		PixelDataInternalFormat internal_format,
		GLint x,
		GLint y,
		GLsizei width,
		GLsizei height,
		GLint border
	) const
	{
		TextureOps::CopyImage2D(
			this->BindTarget(),
			level,
			internal_format,
			x,
			y,
			width,
			height,
			border
		);
	}


	/** Wrapper for Texture::CopyImage1D()
	 *  @see Texture::CopyImage1D()
	 */
	void CopyImage1D(
		GLint level,
		PixelDataInternalFormat internal_format,
		GLint x,
		GLint y,
		GLsizei width,
		GLint border
	) const
	{
		TextureOps::CopyImage1D(
			this->BindTarget(),
			level,
			internal_format,
			x,
			y,
			width,
			border
		);
	}


	/** Wrapper for Texture::CopySubImage3D()
	 *  @see Texture::CopySubImage3D()
	 */
	void CopySubImage3D(
		GLint level,
		GLint xoffs,
		GLint yoffs,
		GLint zoffs,
		GLint x,
		GLint y,
		GLsizei width,
		GLsizei height
	) const
	{
		TextureOps::CopySubImage3D(
			this->BindTarget(),
			level,
			xoffs,
			yoffs,
			zoffs,
			x,
			y,
			width,
			height
		);
	}


	/** Wrapper for Texture::CopySubImage2D()
	 *  @see Texture::CopySubImage2D()
	 */
	void CopySubImage2D(
		GLint level,
		GLint xoffs,
		GLint yoffs,
		GLint x,
		GLint y,
		GLsizei width,
		GLsizei height
	) const
	{
		TextureOps::CopySubImage2D(
			this->BindTarget(),
			level,
			xoffs,
			yoffs,
			x,
			y,
			width,
			height
		);
	}


	/** Wrapper for Texture::CopySubImage1D()
	 *  @see Texture::CopySubImage1D()
	 */
	void CopySubImage1D(
		GLint level,
		GLint xoffs,
		GLint x,
		GLint y,
		GLsizei width
	) const
	{
		TextureOps::CopySubImage1D(
			this->BindTarget(),
			level,
			xoffs,
			x,
			y,
			width
		);
	}


	/** Wrapper for Texture::CompressedImage3D()
	 *  @see Texture::CompressedImage3D()
	 */
	void CompressedImage3D(
		GLint level,
		PixelDataInternalFormat internal_format,
		GLsizei width,
		GLsizei height,
		GLsizei depth,
		GLint border,
		GLsizei image_size,
		const void * data
	) const
	{
		TextureOps::CompressedImage3D(
			this->BindTarget(),
			level,
			internal_format,
			width,
			height,
			depth,
			border,
			image_size,
			data
		);
	}


	/** Wrapper for Texture::CompressedImage2D()
	 *  @see Texture::CompressedImage2D()
	 */
	void CompressedImage2D(
		GLint level,
		PixelDataInternalFormat internal_format,
		GLsizei width,
		GLsizei height,
		GLint border,
		GLsizei image_size,
		const void * data
	) const
	{
		TextureOps::CompressedImage2D(
			this->BindTarget(),
			level,
			internal_format,
			width,
			height,
			border,
			image_size,
			data
		);
	}


	/** Wrapper for Texture::CompressedImage1D()
	 *  @see Texture::CompressedImage1D()
	 */
	void CompressedImage1D(
		GLint level,
		PixelDataInternalFormat internal_format,
		GLsizei width,
		GLint border,
		GLsizei image_size,
		const void * data
	) const
	{
		TextureOps::CompressedImage1D(
			this->BindTarget(),
			level,
			internal_format,
			width,
			border,
			image_size,
			data
		);
	}


	/** Wrapper for Texture::CompressedSubImage3D()
	 *  @see Texture::CompressedSubImage3D()
	 */
	void CompressedSubImage3D(
		GLint level,
		GLint xoffs,
		GLint yoffs,
		GLint zoffs,
		GLsizei width,
		GLsizei height,
		GLsizei depth,
		PixelDataFormat format,
		GLsizei image_size,
		const void * data
	) const
	{
		TextureOps::CompressedSubImage3D(
			this->BindTarget(),
			level,
			xoffs,
			yoffs,
			zoffs,
			width,
			height,
			depth,
			format,
			image_size,
			data
		);
	}


	/** Wrapper for Texture::CompressedSubImage2D()
	 *  @see Texture::CompressedSubImage2D()
	 */
	void CompressedSubImage2D(
		GLint level,
		GLint xoffs,
		GLint yoffs,
		GLsizei width,
		GLsizei height,
		PixelDataFormat format,
		GLsizei image_size,
		const void * data
	) const
	{
		TextureOps::CompressedSubImage2D(
			this->BindTarget(),
			level,
			xoffs,
			yoffs,
			width,
			height,
			format,
			image_size,
			data
		);
	}


	/** Wrapper for Texture::CompressedSubImage1D()
	 *  @see Texture::CompressedSubImage1D()
	 */
	void CompressedSubImage1D(
		GLint level,
		GLint xoffs,
		GLsizei width,
		PixelDataFormat format,
		GLsizei image_size,
		const void * data
	) const
	{
		TextureOps::CompressedSubImage1D(
			this->BindTarget(),
			level,
			xoffs,
			width,
			format,
			image_size,
			data
		);
	}

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_2 || GL_ARB_texture_multisample

	/** Wrapper for Texture::Image3DMultisample()
	 *  @see Texture::Image3DMultisample()
	 */
	void Image3DMultisample(
		GLsizei samples,
		PixelDataInternalFormat internal_format,
		GLsizei width,
		GLsizei height,
		GLsizei depth,
		bool fixed_sample_locations
	) const
	{
		TextureOps::Image3DMultisample(
			this->BindTarget(),
			samples,
			internal_format,
			width,
			height,
			depth,
			fixed_sample_locations
		);
	}
#endif // GL_VERSION_3_2 GL_ARB_texture_multisample

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_2 || GL_ARB_texture_multisample

	/** Wrapper for Texture::Image2DMultisample()
	 *  @see Texture::Image2DMultisample()
	 */
	void Image2DMultisample(
		GLsizei samples,
		PixelDataInternalFormat internal_format,
		GLsizei width,
		GLsizei height,
		bool fixed_sample_locations
	) const
	{
		TextureOps::Image2DMultisample(
			this->BindTarget(),
			samples,
			internal_format,
			width,
			height,
			fixed_sample_locations
		);
	}
#endif // GL_VERSION_3_2 GL_ARB_texture_multisample

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_1

	/** Wrapper for Texture::Buffer()
	 *  @see Texture::Buffer()
	 */
	void Buffer(
		PixelDataInternalFormat internal_format,
		const BufferOps & buffer
	) const
	{
		TextureOps::Buffer(
			this->BindTarget(),
			internal_format,
			buffer
		);
	}
#endif // GL_VERSION_3_1

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_4_3

	/** Wrapper for Texture::BufferRange()
	 *  @see Texture::BufferRange()
	 */
	void BufferRange(
		PixelDataInternalFormat internal_format,
		const BufferOps & buffer,
		GLintptr offset,
		GLsizeiptr size
	) const
	{
		TextureOps::BufferRange(
			this->BindTarget(),
			internal_format,
			buffer,
			offset,
			size
		);
	}
#endif // GL_VERSION_4_3

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_4_2 || GL_ARB_texture_storage

	/** Wrapper for Texture::Storage1D()
	 *  @see Texture::Storage1D()
	 */
	void Storage1D(
		GLsizei levels,
		PixelDataInternalFormat internal_format,
		GLsizei width
	) const
	{
		TextureOps::Storage1D(
			this->BindTarget(),
			levels,
			internal_format,
			width
		);
	}
#endif // GL_VERSION_4_2 GL_ARB_texture_storage

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_4_2 || GL_ARB_texture_storage

	/** Wrapper for Texture::Storage2D()
	 *  @see Texture::Storage2D()
	 */
	void Storage2D(
		GLsizei levels,
		PixelDataInternalFormat internal_format,
		GLsizei width,
		GLsizei height
	) const
	{
		TextureOps::Storage2D(
			this->BindTarget(),
			levels,
			internal_format,
			width,
			height
		);
	}
#endif // GL_VERSION_4_2 GL_ARB_texture_storage

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_4_2 || GL_ARB_texture_storage

	/** Wrapper for Texture::Storage3D()
	 *  @see Texture::Storage3D()
	 */
	void Storage3D(
		GLsizei levels,
		PixelDataInternalFormat internal_format,
		GLsizei width,
		GLsizei height,
		GLsizei depth
	) const
	{
		TextureOps::Storage3D(
			this->BindTarget(),
			levels,
			internal_format,
			width,
			height,
			depth
		);
	}
#endif // GL_VERSION_4_2 GL_ARB_texture_storage


	/** Wrapper for Texture::BaseLevel()
	 *  @see Texture::BaseLevel()
	 */
	GLuint BaseLevel(void) const
	{
		return TextureOps::BaseLevel(
			this->BindTarget()
		);
	}


	/** Wrapper for Texture::BaseLevel()
	 *  @see Texture::BaseLevel()
	 */
	void BaseLevel(
		GLuint level
	) const
	{
		TextureOps::BaseLevel(
			this->BindTarget(),
			level
		);
	}


	/** Wrapper for Texture::BorderColor()
	 *  @see Texture::BorderColor()
	 */
	Vector< GLfloat, 4 > BorderColor(
		TypeTag< GLfloat > _auto_param_2
	) const
	{
		return TextureOps::BorderColor(
			this->BindTarget(),
			_auto_param_2
		);
	}


	/** Wrapper for Texture::BorderColor()
	 *  @see Texture::BorderColor()
	 */
	void BorderColor(
		Vector< GLfloat, 4 > color
	) const
	{
		TextureOps::BorderColor(
			this->BindTarget(),
			color
		);
	}


	/** Wrapper for Texture::BorderColor()
	 *  @see Texture::BorderColor()
	 */
	Vector< GLint, 4 > BorderColor(
		TypeTag< GLint > _auto_param_2
	) const
	{
		return TextureOps::BorderColor(
			this->BindTarget(),
			_auto_param_2
		);
	}


	/** Wrapper for Texture::BorderColor()
	 *  @see Texture::BorderColor()
	 */
	void BorderColor(
		Vector< GLint, 4 > color
	) const
	{
		TextureOps::BorderColor(
			this->BindTarget(),
			color
		);
	}


	/** Wrapper for Texture::BorderColor()
	 *  @see Texture::BorderColor()
	 */
	Vector< GLuint, 4 > BorderColor(
		TypeTag< GLuint > _auto_param_2
	) const
	{
		return TextureOps::BorderColor(
			this->BindTarget(),
			_auto_param_2
		);
	}


	/** Wrapper for Texture::BorderColor()
	 *  @see Texture::BorderColor()
	 */
	void BorderColor(
		Vector< GLuint, 4 > color
	) const
	{
		TextureOps::BorderColor(
			this->BindTarget(),
			color
		);
	}


	/** Wrapper for Texture::CompareMode()
	 *  @see Texture::CompareMode()
	 */
	TextureCompareMode CompareMode(void) const
	{
		return TextureOps::CompareMode(
			this->BindTarget()
		);
	}


	/** Wrapper for Texture::CompareMode()
	 *  @see Texture::CompareMode()
	 */
	void CompareMode(
		TextureCompareMode mode
	) const
	{
		TextureOps::CompareMode(
			this->BindTarget(),
			mode
		);
	}


	/** Wrapper for Texture::CompareFunc()
	 *  @see Texture::CompareFunc()
	 */
	CompareFunction CompareFunc(void) const
	{
		return TextureOps::CompareFunc(
			this->BindTarget()
		);
	}


	/** Wrapper for Texture::CompareFunc()
	 *  @see Texture::CompareFunc()
	 */
	void CompareFunc(
		CompareFunction func
	) const
	{
		TextureOps::CompareFunc(
			this->BindTarget(),
			func
		);
	}


	/** Wrapper for Texture::LODBias()
	 *  @see Texture::LODBias()
	 */
	GLfloat LODBias(void) const
	{
		return TextureOps::LODBias(
			this->BindTarget()
		);
	}


	/** Wrapper for Texture::LODBias()
	 *  @see Texture::LODBias()
	 */
	void LODBias(
		GLfloat value
	) const
	{
		TextureOps::LODBias(
			this->BindTarget(),
			value
		);
	}


	/** Wrapper for Texture::MagFilter()
	 *  @see Texture::MagFilter()
	 */
	TextureMagFilter MagFilter(void) const
	{
		return TextureOps::MagFilter(
			this->BindTarget()
		);
	}


	/** Wrapper for Texture::MagFilter()
	 *  @see Texture::MagFilter()
	 */
	void MagFilter(
		TextureMagFilter filter
	) const
	{
		TextureOps::MagFilter(
			this->BindTarget(),
			filter
		);
	}


	/** Wrapper for Texture::MinFilter()
	 *  @see Texture::MinFilter()
	 */
	TextureMinFilter MinFilter(void) const
	{
		return TextureOps::MinFilter(
			this->BindTarget()
		);
	}


	/** Wrapper for Texture::MinFilter()
	 *  @see Texture::MinFilter()
	 */
	void MinFilter(
		TextureMinFilter filter
	) const
	{
		TextureOps::MinFilter(
			this->BindTarget(),
			filter
		);
	}


	/** Wrapper for Texture::MinLOD()
	 *  @see Texture::MinLOD()
	 */
	GLfloat MinLOD(void) const
	{
		return TextureOps::MinLOD(
			this->BindTarget()
		);
	}


	/** Wrapper for Texture::MinLOD()
	 *  @see Texture::MinLOD()
	 */
	void MinLOD(
		GLfloat value
	) const
	{
		TextureOps::MinLOD(
			this->BindTarget(),
			value
		);
	}


	/** Wrapper for Texture::MaxLOD()
	 *  @see Texture::MaxLOD()
	 */
	GLfloat MaxLOD(void) const
	{
		return TextureOps::MaxLOD(
			this->BindTarget()
		);
	}


	/** Wrapper for Texture::MaxLOD()
	 *  @see Texture::MaxLOD()
	 */
	void MaxLOD(
		GLfloat value
	) const
	{
		TextureOps::MaxLOD(
			this->BindTarget(),
			value
		);
	}


	/** Wrapper for Texture::MaxLevel()
	 *  @see Texture::MaxLevel()
	 */
	GLint MaxLevel(void) const
	{
		return TextureOps::MaxLevel(
			this->BindTarget()
		);
	}


	/** Wrapper for Texture::MaxLevel()
	 *  @see Texture::MaxLevel()
	 */
	void MaxLevel(
		GLint value
	) const
	{
		TextureOps::MaxLevel(
			this->BindTarget(),
			value
		);
	}


	/** Wrapper for Texture::MaxAnisotropy()
	 *  @see Texture::MaxAnisotropy()
	 */
	GLfloat MaxAnisotropy(void) const
	{
		return TextureOps::MaxAnisotropy(
			this->BindTarget()
		);
	}


	/** Wrapper for Texture::Anisotropy()
	 *  @see Texture::Anisotropy()
	 */
	GLfloat Anisotropy(void) const
	{
		return TextureOps::Anisotropy(
			this->BindTarget()
		);
	}


	/** Wrapper for Texture::Anisotropy()
	 *  @see Texture::Anisotropy()
	 */
	void Anisotropy(
		GLfloat value
	) const
	{
		TextureOps::Anisotropy(
			this->BindTarget(),
			value
		);
	}

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_3 || GL_ARB_texture_swizzle

	/** Wrapper for Texture::Swizzle()
	 *  @see Texture::Swizzle()
	 */
	TextureSwizzle Swizzle(
		TextureSwizzleCoord coord
	) const
	{
		return TextureOps::Swizzle(
			this->BindTarget(),
			coord
		);
	}
#endif // GL_VERSION_3_3 GL_ARB_texture_swizzle

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_3 || GL_ARB_texture_swizzle

	/** Wrapper for Texture::Swizzle()
	 *  @see Texture::Swizzle()
	 */
	void Swizzle(
		TextureSwizzleCoord coord,
		TextureSwizzle mode
	) const
	{
		TextureOps::Swizzle(
			this->BindTarget(),
			coord,
			mode
		);
	}
#endif // GL_VERSION_3_3 GL_ARB_texture_swizzle

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_3 || GL_ARB_texture_swizzle

	/** Wrapper for Texture::SwizzleR()
	 *  @see Texture::SwizzleR()
	 */
	TextureSwizzle SwizzleR(void) const
	{
		return TextureOps::SwizzleR(
			this->BindTarget()
		);
	}
#endif // GL_VERSION_3_3 GL_ARB_texture_swizzle

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_3 || GL_ARB_texture_swizzle

	/** Wrapper for Texture::SwizzleR()
	 *  @see Texture::SwizzleR()
	 */
	void SwizzleR(
		TextureSwizzle mode
	) const
	{
		TextureOps::SwizzleR(
			this->BindTarget(),
			mode
		);
	}
#endif // GL_VERSION_3_3 GL_ARB_texture_swizzle

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_3 || GL_ARB_texture_swizzle

	/** Wrapper for Texture::SwizzleG()
	 *  @see Texture::SwizzleG()
	 */
	TextureSwizzle SwizzleG(void) const
	{
		return TextureOps::SwizzleG(
			this->BindTarget()
		);
	}
#endif // GL_VERSION_3_3 GL_ARB_texture_swizzle

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_3 || GL_ARB_texture_swizzle

	/** Wrapper for Texture::SwizzleG()
	 *  @see Texture::SwizzleG()
	 */
	void SwizzleG(
		TextureSwizzle mode
	) const
	{
		TextureOps::SwizzleG(
			this->BindTarget(),
			mode
		);
	}
#endif // GL_VERSION_3_3 GL_ARB_texture_swizzle

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_3 || GL_ARB_texture_swizzle

	/** Wrapper for Texture::SwizzleB()
	 *  @see Texture::SwizzleB()
	 */
	TextureSwizzle SwizzleB(void) const
	{
		return TextureOps::SwizzleB(
			this->BindTarget()
		);
	}
#endif // GL_VERSION_3_3 GL_ARB_texture_swizzle

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_3 || GL_ARB_texture_swizzle

	/** Wrapper for Texture::SwizzleB()
	 *  @see Texture::SwizzleB()
	 */
	void SwizzleB(
		TextureSwizzle mode
	) const
	{
		TextureOps::SwizzleB(
			this->BindTarget(),
			mode
		);
	}
#endif // GL_VERSION_3_3 GL_ARB_texture_swizzle

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_3 || GL_ARB_texture_swizzle

	/** Wrapper for Texture::SwizzleA()
	 *  @see Texture::SwizzleA()
	 */
	TextureSwizzle SwizzleA(void) const
	{
		return TextureOps::SwizzleA(
			this->BindTarget()
		);
	}
#endif // GL_VERSION_3_3 GL_ARB_texture_swizzle

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_3 || GL_ARB_texture_swizzle

	/** Wrapper for Texture::SwizzleA()
	 *  @see Texture::SwizzleA()
	 */
	void SwizzleA(
		TextureSwizzle mode
	) const
	{
		TextureOps::SwizzleA(
			this->BindTarget(),
			mode
		);
	}
#endif // GL_VERSION_3_3 GL_ARB_texture_swizzle

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_3 || GL_ARB_texture_swizzle

	/** Wrapper for Texture::SwizzleRGBA()
	 *  @see Texture::SwizzleRGBA()
	 */
	TextureSwizzleTuple SwizzleRGBA(void) const
	{
		return TextureOps::SwizzleRGBA(
			this->BindTarget()
		);
	}
#endif // GL_VERSION_3_3 GL_ARB_texture_swizzle

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_3 || GL_ARB_texture_swizzle

	/** Wrapper for Texture::SwizzleRGBA()
	 *  @see Texture::SwizzleRGBA()
	 */
	void SwizzleRGBA(
		TextureSwizzle mode
	) const
	{
		TextureOps::SwizzleRGBA(
			this->BindTarget(),
			mode
		);
	}
#endif // GL_VERSION_3_3 GL_ARB_texture_swizzle

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_3 || GL_ARB_texture_swizzle

	/** Wrapper for Texture::SwizzleRGBA()
	 *  @see Texture::SwizzleRGBA()
	 */
	void SwizzleRGBA(
		TextureSwizzle mode_r,
		TextureSwizzle mode_g,
		TextureSwizzle mode_b,
		TextureSwizzle mode_a
	) const
	{
		TextureOps::SwizzleRGBA(
			this->BindTarget(),
			mode_r,
			mode_g,
			mode_b,
			mode_a
		);
	}
#endif // GL_VERSION_3_3 GL_ARB_texture_swizzle

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_3_3 || GL_ARB_texture_swizzle

	/** Wrapper for Texture::SwizzleRGBA()
	 *  @see Texture::SwizzleRGBA()
	 */
	void SwizzleRGBA(
		const TextureSwizzleTuple & modes
	) const
	{
		TextureOps::SwizzleRGBA(
			this->BindTarget(),
			modes
		);
	}
#endif // GL_VERSION_3_3 GL_ARB_texture_swizzle


	/** Wrapper for Texture::Wrap()
	 *  @see Texture::Wrap()
	 */
	TextureWrap Wrap(
		TextureWrapCoord coord
	) const
	{
		return TextureOps::Wrap(
			this->BindTarget(),
			coord
		);
	}


	/** Wrapper for Texture::Wrap()
	 *  @see Texture::Wrap()
	 */
	void Wrap(
		TextureWrapCoord coord,
		TextureWrap mode
	) const
	{
		TextureOps::Wrap(
			this->BindTarget(),
			coord,
			mode
		);
	}


	/** Wrapper for Texture::WrapS()
	 *  @see Texture::WrapS()
	 */
	TextureWrap WrapS(void) const
	{
		return TextureOps::WrapS(
			this->BindTarget()
		);
	}


	/** Wrapper for Texture::WrapS()
	 *  @see Texture::WrapS()
	 */
	void WrapS(
		TextureWrap mode
	) const
	{
		TextureOps::WrapS(
			this->BindTarget(),
			mode
		);
	}


	/** Wrapper for Texture::WrapT()
	 *  @see Texture::WrapT()
	 */
	TextureWrap WrapT(void) const
	{
		return TextureOps::WrapT(
			this->BindTarget()
		);
	}


	/** Wrapper for Texture::WrapT()
	 *  @see Texture::WrapT()
	 */
	void WrapT(
		TextureWrap mode
	) const
	{
		TextureOps::WrapT(
			this->BindTarget(),
			mode
		);
	}


	/** Wrapper for Texture::WrapR()
	 *  @see Texture::WrapR()
	 */
	TextureWrap WrapR(void) const
	{
		return TextureOps::WrapR(
			this->BindTarget()
		);
	}


	/** Wrapper for Texture::WrapR()
	 *  @see Texture::WrapR()
	 */
	void WrapR(
		TextureWrap mode
	) const
	{
		TextureOps::WrapR(
			this->BindTarget(),
			mode
		);
	}

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_4_3

	/** Wrapper for Texture::DepthStencilMode()
	 *  @see Texture::DepthStencilMode()
	 */
	PixelDataFormat DepthStencilMode(void) const
	{
		return TextureOps::DepthStencilMode(
			this->BindTarget()
		);
	}
#endif // GL_VERSION_4_3

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_4_3

	/** Wrapper for Texture::DepthStencilMode()
	 *  @see Texture::DepthStencilMode()
	 */
	void DepthStencilMode(
		PixelDataFormat mode
	) const
	{
		TextureOps::DepthStencilMode(
			this->BindTarget(),
			mode
		);
	}
#endif // GL_VERSION_4_3

#if OGLPLUS_DOCUMENTATION_ONLY || GL_ARB_seamless_cubemap_per_texture

	/** Wrapper for Texture::Seamless()
	 *  @see Texture::Seamless()
	 */
	bool Seamless(void) const
	{
		return TextureOps::Seamless(
			this->BindTarget()
		);
	}
#endif // GL_ARB_seamless_cubemap_per_texture

#if OGLPLUS_DOCUMENTATION_ONLY || GL_ARB_seamless_cubemap_per_texture

	/** Wrapper for Texture::Seamless()
	 *  @see Texture::Seamless()
	 */
	void Seamless(
		bool enable
	) const
	{
		TextureOps::Seamless(
			this->BindTarget(),
			enable
		);
	}
#endif // GL_ARB_seamless_cubemap_per_texture


	/** Wrapper for Texture::GenerateMipmap()
	 *  @see Texture::GenerateMipmap()
	 */
	void GenerateMipmap(void) const
	{
		TextureOps::GenerateMipmap(
			this->BindTarget()
		);
	}

#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_4_3 || GL_ARB_texture_view

	/** Wrapper for Texture::View()
	 *  @see Texture::View()
	 */
	void View(
		const TextureOps & orig_texture,
		PixelDataInternalFormat internal_format,
		GLuint min_level,
		GLuint num_levels,
		GLuint min_layer,
		GLuint num_layers
	) const
	{
		TextureOps::View(
			this->BindTarget(),
			orig_texture,
			internal_format,
			min_level,
			num_levels,
			min_layer,
			num_layers
		);
	}
#endif // GL_VERSION_4_3 GL_ARB_texture_view


}; // class BoundTemplate

} // namespace oglplus

#endif // include guard
