#pragma once

#include "Widget.h"
#include "Core/Math.h"
#include "Runtime/Core/Framework/IRenderBase.h"


class SceneEditor : public Widget
{
public:

	SceneEditor() { }
	~SceneEditor() { }

	void SetRenderer(IRenderBase *pRenderer);
	
	virtual void OnShow() override;
	virtual void OnUpdate() override;
	virtual void OnPaint() override;
	virtual void OnEvent(const Event &event) override;
	virtual void OnClose() override;
	
private:

	IRenderBase *m_pRenderer;

};
