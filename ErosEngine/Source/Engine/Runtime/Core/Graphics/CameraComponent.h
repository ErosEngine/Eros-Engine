#ifndef CAMERA_H
#define CAMERA_H

#include <Core/Common.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "../Entity/ComponentsBase.h"


struct CameraComponent : public ICameraComponent
{
	virtual void CreateFromOther(const IComponent *other) override;
	virtual void FreeResources() override;

	virtual QString ToString() const override;
	virtual ComponentType GetType() const override;

	virtual void Initialize(float width, float height, float zNear, float zFar, CameraType type);

	virtual glm::mat4 GetPerspective() const override;
	virtual glm::mat4 GetModelView() const override;
};


#endif // CAMERA_H
