/*
 * project: Reaching
 * author: Juho Naalisvaara
 * date: 03.11.2010
 *
 */

#include "BackgroundWidget.hpp"
#include <MultiWidgets/Animators.hpp>

namespace Reaching {

  BackgroundWidget::BackgroundWidget(MultiWidgets::Widget * parent)
      : MultiWidgets::Widget(parent),
      m_random(Radiant::TimeStamp::getTime()) // Use time as the random seed
  {}

  BackgroundWidget::~BackgroundWidget() {}

  void BackgroundWidget::createAnimations()
  {

    Radiant::debug("Creating new animations");

    for(ChildIterator it = childBegin(); it != childEnd(); it++) {

      MultiWidgets::Widget * w = *it;

      // Remove any old operators.
      w->clearOperators();

      float t = m_random.randMinMax(0.1f, 1.0f); // Animation time, in seconds

      // Animate the location of the widget:
      MultiWidgets::AnimatorVector2f * a1 =
          new MultiWidgets::AnimatorVector2f("location");
      // Start from current location:
      a1->addKey(0.0f, w->location());
      // Animate to random location:
      a1->addKey(t, Nimble::Vector2(50 + m_random.rand0X(width() - 100),
                                    50 + m_random.rand0X(height() - 100)));
      w->addOperator(a1);


      /*
      // Animate the scale of the widget:
      MultiWidgets::AnimatorScale * a2 =
          new MultiWidgets::AnimatorScale();
      // Start from current scale:
      a2->addKey(0.0, w->scale());
      // Animate to random scale:
      a2->addKey(t, 0.2 + m_random.rand0X(2.2));

      w->addOperator(a2);
      */


      /*
      // Animate the color of the widget:
      MultiWidgets::AnimatorVector4f * a3 =
          new MultiWidgets::AnimatorVector4f("color");
      // Start from current color:
      a3->addKey(0.0, w->color());
      // Animate to random color:
      a3->addKey(t, Nimble::Vector4(m_random.rand01(),
                                    m_random.rand01(),
                                    m_random.rand01(),
                                    m_random.randMinMax(0.5, 1.0)));
      w->addOperator(a3);
      */
    }

    //
    /*
    Animate the color of this widget:
    MultiWidgets::AnimatorVector4f * acolor =
        new MultiWidgets::AnimatorVector4f("color");
    acolor->addKey(0, color());
    // Animate to some rather dark color:
    acolor->addKey(m_random.randMinMax(0.1f, 5.0f),
               Nimble::Vector4(m_random.rand0X(0.3f),
                               m_random.rand0X(0.3f),
                               m_random.rand0X(0.3f),
                               1.0f));
    this->addOperator(acolor);
    */

  }


  void BackgroundWidget::singleTap(MultiWidgets::GrabManager & )
  {
    createAnimations();
  }

}
