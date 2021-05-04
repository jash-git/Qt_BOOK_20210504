#include <QtGui>

#include "CustomStyle.h"
#include "RoundPushBtn.h"


CCustomStyle::CCustomStyle(const QString& backgroundIcon,
                                                   const QString& buttonIcon)
                                                   :	m_sBackgroundIcon(backgroundIcon),
                                                   m_sButtonIcon(buttonIcon)
{
}

/// 上色
void CCustomStyle::polish(QPalette &palette)
 {
        // 調色板
        palette = QPalette(QColor(52, 52, 52));
        palette.setBrush(QPalette::BrightText, Qt::green);
        palette.setBrush(QPalette::Base, QColor(52, 52, 52));
        palette.setBrush(QPalette::Highlight, QColor(0, 60, 0));
        palette.setBrush(QPalette::Text, QColor(0, 0, 0));
        palette.setBrush(QPalette::ButtonText, QColor(0, 0, 0));
        palette.setBrush(QPalette::WindowText, QColor(0, 0, 0));
        palette.setBrush(QPalette::Button, Qt::black);
        palette.setBrush(QPalette::Light, QColor(0, 85, 0));
        palette.setBrush(QPalette::Mid, Qt::black);
        palette.setBrush(QPalette::Midlight, Qt::black);
        palette.setBrush(QPalette::Dark,  QColor(0, 85, 0));
        palette.setBrush(QPalette::Shadow, Qt::black);
        palette.setBrush(QPalette::Window, Qt::black);

        changeTexture(palette);

        QBrush brush = palette.base();
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush);
 }

void CCustomStyle::changeTexture(QPalette & palette)
{
        if((!m_sBackgroundIcon.isNull()) && (!m_sBackgroundIcon.isEmpty()))
        {// 背景圖片存在
                QPixmap backgroundImage(m_sBackgroundIcon);
                setTexture(palette, QPalette::Window, backgroundImage);
        }


        if(!(m_sButtonIcon.isNull() || m_sButtonIcon.isEmpty()))
        {// 背景圖片存在
                QPixmap buttonImage(m_sButtonIcon);
                QPixmap midImage = buttonImage;

                setTexture(palette, QPalette::Button, buttonImage);
                setTexture(palette, QPalette::Mid, midImage);
        }
}


void CCustomStyle::setTexture(QPalette &palette, QPalette::ColorRole role,
                                                          const QPixmap &pixmap)
{
        for (int i = 0; i < QPalette::NColorGroups; ++i)
        {
                QColor color = palette.brush(QPalette::ColorGroup(i), role).color();
                palette.setBrush(QPalette::ColorGroup(i), role, QBrush(color, pixmap));
        }
}
/// 繪制簡單元素
void CCustomStyle::drawPrimitive(PrimitiveElement element,
                                                                 const QStyleOption *option,
                                                                 QPainter *painter,
                                                                 const QWidget *pWidget ) const
{
        switch (element)
        {
        case PE_PanelButtonCommand:
                {
                        const CRoundPushBtn* btn = qobject_cast<const CRoundPushBtn*>(pWidget);

                        QColor backgroundColor = QColor(0, 190, 0);
                        QColor lightBorderColor = QColor(120, 120, 120);
                        QColor darkBorderColor = QColor(60, 60, 60);
                        int		nLineWidth = 3;

                        if(btn)
                        {// 按鈕風格為"燈"
                                switch(btn->m_Stat)
                                {
                                case CRoundPushBtn::StatFault:	// 故障
                                        backgroundColor	= QColor(255, 0, 0);
                                        break;
                                case CRoundPushBtn::StatUnknown:	// 未知
                                        backgroundColor	= QColor(255, 255, 0);
                                        break;
                                case CRoundPushBtn::StatFine:	// 正常
                                        backgroundColor	= QColor(0, 255, 0);
                                        break;
                                default:						// 關機
                                        backgroundColor	= QColor(0, 0, 0);
                                        break;
                                }
                        }
                        int x, y, width, height;
                        option->rect.getRect(&x, &y, &width, &height);

                        QPainterPath roundRect = roundRectPath(option->rect);
                        int radius = qMin(width, height) / 2;

                        QBrush brush;
                        bool darker;

                        const QStyleOptionButton *buttonOption =
                                qstyleoption_cast<const QStyleOptionButton *>(option);
                        if (buttonOption
                                && (buttonOption->features & QStyleOptionButton::Flat))
                        {
                                brush = option->palette.background();
                                darker = (option->state & (State_Sunken | State_On));
                        }
                        else
                        {
                                if (option->state & (State_Sunken | State_On))
                                {
                                        brush = option->palette.mid();
                                        darker = !(option->state & State_Sunken);
                                }
                                else
                                {
                                        brush = option->palette.button();
                                        darker = false;
                                }
                        }

                        painter->save();
                        painter->setRenderHint(QPainter::Antialiasing, true);
                        painter->fillPath(roundRect, brush);

                        if (darker)
                        {
                                painter->fillPath(roundRect, backgroundColor);
                        }

                        int penWidth;
                        if (radius < 10)
                        {
                                penWidth = nLineWidth-4;
                        }
                        else if (radius < 20)
                        {
                                penWidth = nLineWidth-2;
                        }
                        else
                        {
                                penWidth = nLineWidth;
                        }

                        QPen topPen(lightBorderColor, penWidth);
                        QPen bottomPen(darkBorderColor, penWidth);

                        if (option->state & (State_Sunken | State_On))
                        {
                                qSwap(topPen, bottomPen);
                        }

                        int x1 = x;
                        int x2 = x + radius;
                        int x3 = x + width - radius;
                        int x4 = x + width;

                        if (option->direction == Qt::RightToLeft)
                        {
                                qSwap(x1, x4);
                                qSwap(x2, x3);
                        }

                        QPoint p1(x1, y);
                        QPoint p2(x4, y);
                        QPoint p3(x3, y + radius);
                        QPoint p4(x2, y + height - radius);
                        QPoint p5(x1, y + height);
                        QPolygon topHalf;
                        topHalf << p1
                                << p2
                                << p3
                                << p4
                                << p5;

                        painter->setClipPath(roundRect);
                        painter->setClipRegion(topHalf, Qt::IntersectClip);
                        painter->setPen(topPen);
                        painter->drawPath(roundRect);

                        QPoint p6(x4, y + height);
                        QPolygon bottomHalf = topHalf;
                        bottomHalf[0] = p6;

                        painter->setClipPath(roundRect);
                        painter->setClipRegion(bottomHalf, Qt::IntersectClip);
                        painter->setPen(bottomPen);
                        painter->drawPath(roundRect);

                        painter->restore();

                        break;
                }
        default:
                {
                        QWindowsStyle::drawPrimitive(element, option, painter, pWidget);
                        break;
                }
        }
}


/// 獲取圓形路徑
QPainterPath CCustomStyle::roundRectPath(const QRect &rect)
{
        // 半徑
        int radius = qMin(rect.width(), rect.height()) / 2;
        int diam = 2 * radius;

        // 獲取區域
        int x1, y1, x2, y2;
        rect.getCoords(&x1, &y1, &x2, &y2);

        // 初始化路徑
        QPoint p1(x2, y1 + radius);
        QPoint p2(x1 + radius, y1);
        QPoint p3(x1 + radius, y2);
        QRect rect1(x2 - diam, y1, diam, diam);
        QRect rect2(x1, y1, diam, diam);
        QRect rect3(x1, y2 - diam, diam, diam);
        QRect rect4(x2 - diam, y2 - diam, diam, diam);

        QPainterPath path;
        path.moveTo(p1);
        path.arcTo(rect1, 0.0, +90.0);
        path.lineTo(p2);
        path.arcTo(rect2, 90.0, +90.0);
        path.lineTo(x1, y2 - radius);
        path.arcTo(rect3, 180.0, +90.0);
        path.lineTo(p3);
        path.arcTo(rect4, 270.0, +90.0);
        path.closeSubpath();

        // 返迴路徑
        return path;
}



