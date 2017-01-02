#include "SceneViewport.h"
#include <QPaintEvent>
#include <QShowEvent>
#include <QKeyEvent>
#include <QMouseEvent>


SceneViewport::SceneViewport(QWidget *parent) : QWidget(parent)
{
	setAttribute(Qt::WA_NativeWindow,			true);
	setAttribute(Qt::WA_PaintOnScreen,			true);
	setAttribute(Qt::WA_AcceptDrops,			true);
	setAttribute(Qt::WA_MSWindowsUseDirect3D,	true);
	setAttribute(Qt::WA_NoSystemBackground,		true);
}

void SceneViewport::SetRenderer(IRenderBase *pRenderer)
{
	pRenderer->Create((GenericHandle)winId(), width(), height(), 1);
	m_pRenderer = pRenderer;
}

QPaintEngine *SceneViewport::paintEngine() const
{
	return NULL;
}

void SceneViewport::showEvent(QShowEvent *showEvent)
{
	m_pRenderer->Clear();
	update();
}

void SceneViewport::paintEvent(QPaintEvent *paintEvent)
{
	m_pRenderer->Clear();
	
	m_pRenderer->Swap();
	update();
}

void SceneViewport::keyPressEvent(QKeyEvent *e)
{
	
}

void SceneViewport::mouseMoveEvent(QMouseEvent *e)
{
	
}
