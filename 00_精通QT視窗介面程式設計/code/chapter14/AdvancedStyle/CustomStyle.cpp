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

void CCustomStyle::polish(QWidget *widget)
{
        QLabel* label			= 0;
        if(label = qobject_cast<QLabel *>(widget))
        {// 標簽

                if(label->frameShape()!= QFrame::NoFrame)
                {
                        QPalette palette = widget->palette();
                        palette.setColor(QPalette::WindowText, Qt::red);
                        palette.setColor(QPalette::Window, Qt::lightGray);
                        palette.setColor(QPalette::Light, Qt::darkGray);
                        palette.setColor(QPalette::Dark, Qt::darkGray);
                        widget->setAutoFillBackground(true);

                        widget->setPalette(palette);
                }
        }
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

/// 繪制控件
void CCustomStyle::drawControl(ControlElement element,
                                                           const QStyleOption *option,
                                                           QPainter *painter,
                                                           const QWidget *widget) const
{
        // 元素分類
        switch (element)
        {//
        case CE_TabBarTab:	// 條
                if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option))
                {

                        QStyleOptionTab myOption = *tab;
                        if((!m_sButtonIcon.isNull()) && (!m_sButtonIcon.isEmpty()))
                        {// 背景圖片存在
                                QPalette tabPal = myOption.palette;
                                QPixmap buttonImage(m_sButtonIcon);
                                QPixmap midImage = buttonImage;

                                setTexture(tabPal, QPalette::Shadow, buttonImage);
                                setTexture(tabPal, QPalette::Mid, midImage);

                                myOption.palette = tabPal;
                        }
                        drawControl(CE_TabBarTabShape, &myOption, painter, widget);
                        drawControl(CE_TabBarTabLabel, &myOption, painter, widget);
                }
                break;
        case CE_TabBarTabShape:
                {
                        const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option);
                        if (tab)
                        {// 選項可用
                                QBrush	brushFill(Qt::darkRed);
                                QTabBar::Shape nShape = QTabBar::TriangularNorth;
                                QPalette palette = tab->palette;
                                switch(tab->shape)
                                {
                                case QTabBar::RoundedNorth:
                                case QTabBar::TriangularNorth:
                                        nShape	= QTabBar::TriangularNorth;
                                        break;
                                case QTabBar::RoundedSouth:
                                case QTabBar::TriangularSouth:
                                        nShape	= QTabBar::TriangularSouth;
                                        break;
                                case QTabBar::RoundedWest:
                                case QTabBar::TriangularWest:
                                        nShape	= QTabBar::TriangularWest;
                                        break;
                                case QTabBar::RoundedEast:
                                case QTabBar::TriangularEast:
                                        nShape	= QTabBar::TriangularEast;
                                        break;
                                default:
                                        break;
                                }

                                bool selected = tab->state & State_Selected;
                                bool onlyOne = tab->position == QStyleOptionTab::OnlyOneTab;
                                QColor light = palette.light().color();
                                QColor midlight = palette.midlight().color();
                                QColor dark = palette.dark().color();
                                QColor shadow = palette.shadow().color();
                                QColor background = tab->palette.background().color();
                                int borderThinkness = pixelMetric(PM_TabBarBaseOverlap, tab, widget);
                                if (selected)
                                        borderThinkness /= 2;

                                if (selected)
                                        painter->setBrush(palette.base());
                                else
                                        painter->setBrush(palette.shadow());

                                QRect r2(option->rect);

                                painter->save();

                                QStyleOptionTab optTab = *tab;
                                QRect rect(tab->rect);
                                int tabOverlap = onlyOne ? 0 : pixelMetric(PM_TabBarTabOverlap, option, widget);

                                if (!selected)
                                {
                                        switch (nShape)
                                        {
                                        case QTabBar::TriangularNorth:
                                                rect.adjust(0, 0, 0, -tabOverlap);
                                                if(!selected)
                                                        rect.adjust(1, 1, -1, 0);
                                                break;
                                        case QTabBar::TriangularSouth:
                                                rect.adjust(0, tabOverlap, 0, 0);
                                                if(!selected)
                                                        rect.adjust(1, 0, -1, -1);
                                                break;
                                        case QTabBar::TriangularEast:
                                                rect.adjust(tabOverlap, 0, 0, 0);
                                                if(!selected)
                                                        rect.adjust(0, 1, -1, -1);
                                                break;
                                        case QTabBar::TriangularWest:
                                                rect.adjust(0, 0, -tabOverlap, 0);
                                                if(!selected)
                                                        rect.adjust(1, 1, 0, -1);
                                                break;
                                        default:
                                                break;
                                        }
                                }

                                painter->setPen(QPen(palette.foreground(), 0));
                                if (selected)
                                        painter->setBrush(brushFill);
                                else
                                        painter->setBrush(palette.shadow());

                                int y;
                                int x;
                                QPolygon a(10);
                                switch (nShape)
                                {
                                case QTabBar::TriangularNorth:
                                case QTabBar::TriangularSouth:
                                        {
                                                a.setPoint(0, 0, -1);
                                                a.setPoint(1, 0, 0);
                                                y = rect.height() - 2;
                                                x = y / 3;
                                                a.setPoint(2, x++, y - 1);
                                                ++x;
                                                a.setPoint(3, x++, y++);
                                                a.setPoint(4, x, y);

                                                int i;
                                                int right = rect.width() - 1;
                                                for (i = 0; i < 5; ++i)
                                                        a.setPoint(9 - i, right - a.point(i).x(), a.point(i).y());
                                                if (nShape == QTabBar::TriangularNorth)
                                                        for (i = 0; i < 10; ++i)
                                                                a.setPoint(i, a.point(i).x(), rect.height() - 1 - a.point(i).y());

                                                a.translate(rect.left(), rect.top());
                                                painter->setRenderHint(QPainter::Antialiasing);
                                                painter->translate(0, 0.5);

                                                QPainterPath path;
                                                path.addPolygon(a);
                                                painter->drawPath(path);
                                                break; }
                                case QTabBar::TriangularEast:
                                case QTabBar::TriangularWest:
                                        {
                                                a.setPoint(0, -1, 0);
                                                a.setPoint(1, 0, 0);
                                                x = rect.width() - 2;
                                                y = x / 3;
                                                a.setPoint(2, x - 1, y++);
                                                ++y;
                                                a.setPoint(3, x++, y++);
                                                a.setPoint(4, x, y);
                                                int i;
                                                int bottom = rect.height() - 1;
                                                for (i = 0; i < 5; ++i)
                                                {
                                                        a.setPoint(9 - i, a.point(i).x(), bottom - a.point(i).y());
                                                }
                                                if (nShape == QTabBar::TriangularWest)
                                                {
                                                        for (i = 0; i < 10; ++i)
                                                        {
                                                                a.setPoint(i, rect.width() - 1 - a.point(i).x(), a.point(i).y());
                                                        }
                                                }
                                                a.translate(rect.left(), rect.top());
                                                painter->setRenderHint(QPainter::Antialiasing);
                                                painter->translate(0.5, 0);
                                                QPainterPath path;
                                                path.addPolygon(a);
                                                painter->drawPath(path);
                                                break;
                                        }
                                default:
                                        break;
                                }
                                painter->restore();
                        }

                        break;
                }
        case CE_TabBarTabLabel:	// tabwidget文本
                {
                        const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option);
                        if (tab)
                        {
                                QStyleOptionTabV2 tabV2(*tab);
                                QStyleOptionTab		optionTab = *tab;

                                QRect tr = tabV2.rect;
                                bool verticalTabs = tabV2.shape == QTabBar::RoundedEast
                                        || tabV2.shape == QTabBar::RoundedWest
                                        || tabV2.shape == QTabBar::TriangularEast
                                        || tabV2.shape == QTabBar::TriangularWest;
                                bool selected = tabV2.state & State_Selected;
                                if (verticalTabs)
                                {
                                        painter->save();
                                        int newX, newY, newRot;
                                        if (tabV2.shape == QTabBar::RoundedEast || tabV2.shape == QTabBar::TriangularEast)
                                        {
                                                newX = tr.width();
                                                newY = tr.y();
                                                newRot = 90;
                                        } else
                                        {
                                                newX = 0;
                                                newY = tr.y() + tr.height();
                                                newRot = -90;
                                        }
                                        tr.setRect(0, 0, tr.height(), tr.width());
                                        QTransform m;
                                        m.translate(newX, newY);
                                        m.rotate(newRot);
                                        painter->setTransform(m, true);
                                }
                                tr.adjust(0, 0, pixelMetric(QStyle::PM_TabBarTabShiftHorizontal, tab, widget),
                                        pixelMetric(QStyle::PM_TabBarTabShiftVertical, tab, widget));

                                if (selected)
                                {
                                        tr.setBottom(tr.bottom() - pixelMetric(QStyle::PM_TabBarTabShiftVertical, tab, widget));
                                        tr.setRight(tr.right() - pixelMetric(QStyle::PM_TabBarTabShiftHorizontal, tab, widget));
                                }

                                int alignment = Qt::AlignCenter | Qt::TextShowMnemonic;
                                if (!styleHint(SH_UnderlineShortcut, option, widget, 0))
                                        alignment |= Qt::TextHideMnemonic;

                                if (!tabV2.icon.isNull()){
                                        QSize iconSize = tabV2.iconSize;
                                        if (!iconSize.isValid())
                                        {
                                                int iconExtent = pixelMetric(PM_SmallIconSize, option, widget);
                                                iconSize = QSize(iconExtent, iconExtent);
                                        }
                                        QPixmap tabIcon = tabV2.icon.pixmap(iconSize,
                                                (tabV2.state & State_Enabled) ? QIcon::Normal
                                                : QIcon::Disabled);
                                        painter->drawPixmap(tr.left() + 6, tr.center().y() - tabIcon.height() / 2, tabIcon);
                                        tr.setLeft(tr.left() + iconSize.width() + 4);
                                }

                                if (selected)
                                        optionTab.palette.setColor(QPalette::WindowText, Qt::yellow);

                                drawItemText(painter, tr, alignment, optionTab.palette, tab->state & State_Enabled, tab->text, QPalette::WindowText);	//
                                if (verticalTabs)
                                        painter->restore();
                        }
                        break;
                }
        default:
                QWindowsStyle::drawControl(element, option, painter, widget);
        }
}
void CCustomStyle::drawComplexControl(ComplexControl control,
                                                                          const QStyleOptionComplex *option,
                                                                          QPainter *painter,
                                                                          const QWidget *widget) const
{
        // 控件
        switch (control)
        {// 孔徑分類
        case CC_ComboBox:
                {// 下拉框
                        QStyleOptionComboBox myOption;
                        const QStyleOptionComboBox *tmpOption =
                                qstyleoption_cast<const QStyleOptionComboBox *>(option);
                        if (tmpOption)
                        {// 選項可用
                                myOption = *tmpOption;
                                myOption.palette.setColor(QPalette::Text,	Qt::red);
                                myOption.palette.setColor(QPalette::Light, Qt::gray);
                                myOption.palette.setColor(QPalette::Dark, Qt::gray);

                                // 畫刷
                                QBrush brush = myOption.palette.window();
                                brush.setColor(brush.color().dark());

                                myOption.palette.setBrush(QPalette::Disabled, QPalette::Text, Qt::darkRed);//brush);
                                myOption.palette.setBrush(QPalette::Disabled, QPalette::Light, Qt::darkGray);
                                myOption.palette.setBrush(QPalette::Disabled, QPalette::Dark, Qt::darkGray);
                        }

                        // 繪制
                        QWindowsStyle::drawComplexControl(control, &myOption, painter, widget);
                        break;
                }
        default:	// 默認
                QWindowsStyle::drawComplexControl(control, option, painter, widget);
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



