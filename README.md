# FlipBook

## Functionality:
  * Create a Generic FlipBook.
  * Flipbook pages contain images or text defined by the User.
  * Animation of Flipping of Pages with a specified Delay.
  * We can render custom text, images onto the Pages.
  * Navigation through the Pages.
  * Input from keyboard to Navigate, or time based.

## Program Details :
  * Written in C++.
  * Opengl Library utilised
  * Following functionality from Opengl implemented
    * Keyboard Interactions.
    * Mouse Interactions.
    * 3D and 2D Transformations.
    * Stroke Text.
    * Timing Functions.
    * Lighting and Shading.
    * Perspective and Parallel Viewing.
    * Texture Mapping.
  * Soil Library required for image loading.
  * Generic Flipbook Class Created [ Library ]
      - Book flipbook(x, y ,z); -> To create a Flipbook at specified position
      - flipbook.addPage(PAGE_TYPE_TEXT, char* string)
          + string -> text here is rendered onto the screen at that Page.
      - flipbook.addPage(PAGE_TYPE_DRAWING, funct)
          + funct(xstart, ystart,z , xmax, ymax)
          + Specified function called, and what is drawn in this function is rendered onto the page.
      - flipbook.renderBook() -> Render Flipbook at that position.
      - flipbook.renderPage() -> Render last page added.
      - flipbook.renderPage(x) -> render Page x on screen.

## Execution :
```
  # Posix Compliant

  ## Installation of libraries
  > sudo apt-get install -y freeglut3-dev libsoil-dev

  ## Execution of Application
  > cd Flipbook
  > make all
  > make run

  # Windows
  > Download make utility http://gnuwin32.sourceforge.net/packages/make.htm
  > Install Opengl Library
  > make all
  > make run
```

##Screenshots

![Image](/img/Screenshots/1.png "Welcome Screen")

![Image](/img/Screenshots/2.png "Flip and View type")

![Image](/img/Screenshots/3.png "Flip and View Type")

![Image](/img/Screenshots/4.png "View Type")

![Image](/img/Screenshots/5.png "Flip type")

![Image](/img/Screenshots/6.png "Flip type")

![Image](/img/Screenshots/7.png "Options List")