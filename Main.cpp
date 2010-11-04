/*
 *  project: Reaching
 *  author: Juho Naalisvaara
 *  date: 02.11.2010
 */

#include "BackgroundWidget.hpp"
#include <cstdlib>
#include <MultiWidgets/ImageWidget.hpp>
#include <MultiWidgets/SimpleSDLApplication.hpp>
#include <MultiWidgets/StayInsideParentOperator.hpp>
#include <Radiant/Directory.hpp>

int main(int argc, char ** argv) {
    SDL_Init(SDL_INIT_VIDEO);

    MultiWidgets::SimpleSDLApplication app;

    if (!app.simpleInit(argc, argv))
        return 1;

    const char * dirpath = "images";

    /* we dont need command line arguments
    for(int i = 0; i < argc; i++) {

      if((strcmp(argv[i], "--dir") == 0) && ((i + 1) < argc)) {
        dirpath = argv[i+1];
        i++;
      }
    }
     */

    // Open a directory with images:
    Radiant::Directory directory(dirpath, "jpeg,jpg,png");

    // Check that there are images to load
    if (!directory.count()) {
        Radiant::error("There are no image files in directory \"%s\"\n"
                "Please use --dir option to specify directory", dirpath);
        return 0;
    }

    Reaching::BackgroundWidget * b = new Reaching::BackgroundWidget(app.root());
    b->setSize(app.size());
    b->setInputFlags(MultiWidgets::Widget::INPUT_PASS_TO_CHILDREN | MultiWidgets::Widget::INPUT_USE_SINGLE_TAPS);

    float imagesize = app.size().minimum() * 0.25f;
    srand(time(0));

    // Create an image widget for each image file
    for (int i = 0; i < directory.count(); i++) {

        // Create an image widget:
        MultiWidgets::ImageWidget * w =
                new MultiWidgets::ImageWidget(b);

        if (w->load(directory.fileNameWithPath(i))) {

            w->resizeToFit(Nimble::Vector2(imagesize, imagesize));
            w->setLocation(Nimble::Vector2(rand()% app.size().x- imagesize, rand()%app.size().y));
            w->addOperator(new MultiWidgets::StayInsideParentOperator());
            //app.root()->addChild(w);
        } else {
            Radiant::error("Could not load image file \"%s\"",
                    directory.fileNameWithPath(i).c_str());
            delete w;
        }
    }

    b->createAnimations();

    // Run the application:
    return app.run();
}
