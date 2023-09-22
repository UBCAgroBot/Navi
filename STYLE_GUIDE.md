# Programming Style Guide for Agrobot Navigation Team
Please write code and conduct code review following this style guide.

## Naming Conventions
### Variables
- Use full words, snake_case, descriptive names. Don't use more than 30 characters, try to limit to 15 characters when possible.
```
int camera_frame_counter; // YES
int cfc;                  // NO
int cameraFrameCounter    // NO
```

- If the variable is local and used in close proximity to initialization, it is ok to use shorter names. In this case, make sure the sequence of characters does not mean something else.
```
for (int i = 0; i < 10; i++)
{
  printf(i);
} // YES

for (int txt = 0; i < 10; i++)
{
  printf(txt);
} // NO
```
### Constants and Macros
- Use ALL_CAPS_SNAKE_CASE, try to keep the length to one or two words. Use full words unless a very well known short version exists.
```
#define PI 3.14             // YES
const int FRAME_RATE = 30;  // YES
```
### Functions
- Use full words, snake_case, descriptive names. Don't use more than 30 characters, try to limit to 15 characters when possible.
```
int distance(Point* p1, Point* p2); // YES
int dst(point* p1, point* p2)       // NO
```
- Use descriptive parameter names if other elements of the declaration does not tell what the parameters are.
```
int distance(point* p1, point* p2); // YES
int distance(double x1, double y1, double x2, double y2); // OK
int distance(double a, double b, double c, double d); // NO
```
### Classes and Structs
- Use full words, Capitalized_Snake_Case, descriptive names. Try to use only one word for struct and class names if possible.
```
struct Point;           // YES
class Camera_Interface; // YES
class cam_interface     // NO
```

### Files
- Use full words, snake_case, descriptive names.
```
camera_handlers.cpp // YES
camcode.cpp         // NO
```
- Have a `.hpp` file and a `.cpp` file with the same name for the declaration and implementation of the same functionality.
