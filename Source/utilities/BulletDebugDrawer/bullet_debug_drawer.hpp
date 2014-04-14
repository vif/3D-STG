#pragma once

#include <LinearMath/btIDebugDraw.h>
#include <oglplus.hpp>
#include <list>

//Implements a simple bullet debug drawer, but delays rendering until we have created all the lines that need to be drawn
class btOGLDebugDrawer : public btIDebugDraw
{
public:
	btOGLDebugDrawer(oglplus::Program* program);

	//accumulates lines to draw
	void drawLine(const btVector3& from, const btVector3& to, const btVector3& color) override;

	//things that are purely virtual but we haven't implemented
	void drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color){}
	void reportErrorWarning(const char* warningString){}
	void draw3dText(const btVector3& location, const char* textString){}
	void setDebugMode(int debugMode){}
	int	getDebugMode() const{ return DBG_DrawWireframe; }

	struct Vertex
	{
		glm::vec4 position;
		glm::vec4 colour;
	};

	//draws the lines we have accumulated and discards them
	void drawAndClear(glm::mat4 view_matrix, glm::mat4 projection_matrix);
private:
	oglplus::Program* _program;
	oglplus::Uniform<oglplus::Mat4f> model_view_projection_matrix_uniform;
	std::list<Vertex> _lines;
	oglplus::VertexArray _vao;
	oglplus::Buffer _vbo;
};