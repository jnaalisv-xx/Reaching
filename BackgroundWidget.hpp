/*
 * project: Reaching
 * author: Juho Naalisvaara
 * date: 03.11.2010
 *
 */

#ifndef BACKGROUND_WIDGET_HPP
#define BACKGROUND_WIDGET_HPP

#include <MultiWidgets/Widget.hpp>
#include <Nimble/Random.hpp>

namespace Reaching {

  class BackgroundWidget : public virtual MultiWidgets::Widget
  {
  public:
    BackgroundWidget(MultiWidgets::Widget * parent = 0);
    
    virtual ~BackgroundWidget();
    
    void createAnimations();

  protected:

    virtual void singleTap(MultiWidgets::GrabManager & );

  private:
     
    Nimble::RandomUniform m_random;
  };
  
}

#endif

