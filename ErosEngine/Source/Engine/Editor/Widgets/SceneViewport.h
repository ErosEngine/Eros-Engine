#ifndef SCENEVIEWPORT_H
#define SCENEVIEWPORT_H

#include <QWidget>
#include "Core/Platform.h"
#include "Runtime/Core/Framework/IRenderBase.h"


class SceneViewport : public QWidget
{
	Q_OBJECT
	
public:
	explicit SceneViewport(QWidget *parent = nullptr);
	
	// This HAS to be called before show()
	void SetRenderer(IRenderBase *pRenderer);
	void SetVSyncEnabled(bool vsync);
	
protected:
	
	// Qt's reimplemented functions
	virtual QPaintEngine *paintEngine() const override;
	virtual void showEvent(QShowEvent *showEvent) override;
	virtual void paintEvent(QPaintEvent *paintEvent) override;
	virtual void keyPressEvent(QKeyEvent *e) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;
	
private:
	
	IRenderBase *m_pRenderer = nullptr;
	bool		 m_isVSync = true;
	
};

#endif // SCENEVIEWPORT_H
