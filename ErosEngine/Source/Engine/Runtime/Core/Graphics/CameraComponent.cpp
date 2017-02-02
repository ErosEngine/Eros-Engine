#include "CameraComponent.h"
#include <QtCore/QDebug>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

void CameraComponent::CreateFromOther(const IComponent *other)
{
	if (other->GetType() != ComponentType_CAMERA)
		return;

	CameraComponent *pOther = (CameraComponent *)other;
	/*
	position =		pOther->position;
	target =		pOther->target;
	up =			pOther->up;
	sensitivity =	pOther->sensitivity;
	prevMousePos =	pOther->prevMousePos;
	xRot =			pOther->xRot;
	yRot =			pOther->yRot;
	speed =			pOther->speed;
	*/
}

void CameraComponent::FreeResources()
{
	if (this)
		delete this;
}

QString CameraComponent::ToString() const
{
	return "Camera Component";
}

ComponentType CameraComponent::GetType() const
{
	return ComponentType_CAMERA;
}

void CameraComponent::Initialize(float width, float height, float zNear, float zFar, CameraType type)
{
}

glm::mat4 CameraComponent::GetPerspective() const
{
	return glm::mat4();
}

glm::mat4 CameraComponent::GetModelView() const
{
	return glm::mat4();
}

/*
void CameraComponent::MouseUpdate(Sint32 x, Sint32 y)
{
    glm::vec2 currentMousePos(x, y);
    glm::vec2 mouseDelta = currentMousePos - prevMousePos;
    
    if (glm::length(mouseDelta) > 50.0f)
    {
        prevMousePos = currentMousePos;
        return;
    }
    glm::vec3 rightAxis = glm::cross(target, up);
    target = glm::mat3x3(
        glm::rotate(-mouseDelta.x * sensitivity, up) * 
        glm::rotate(-mouseDelta.y * sensitivity, rightAxis)
    ) * target;
    
    prevMousePos = currentMousePos;
}

void CameraComponent::StrafeRight()
{
    position += glm::normalize(glm::cross(target, up)) * speed;
}

void CameraComponent::StrafeLeft()
{
    position -= glm::normalize(glm::cross(target, up)) * speed;
}

void CameraComponent::MoveForward()
{
    position += target * speed;
}

void CameraComponent::SprintForward(float multiplier)
{
    position += target * (speed * multiplier);
}

void CameraComponent::MoveDownward()
{
    position -= up * speed;
}
void CameraComponent::MoveUp()
{
    position += up * speed;
}

void CameraComponent::MoveBack()
{
    position -= target * speed;
}

void CameraComponent::UpdatePerspective(float fov_, float zNear_, float zFar_, float aspect_)
{
    this->fov = fov_;
    this->zNear = zNear_;
    this->zFar = zFar_;
    this->aspect = aspect_;
}

*/