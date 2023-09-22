# Programming Style Guide for Agrobot Navigation Team
Please write code and conduct code review following this style guide.

## Naming Conventions
### Variables
- Use full words, snake_case, descriptive names.
```
int camera_frame_counter; // YES
int cfc;                  // NO
```

- If the variable is local and used in close proximity to initialization, it is ok to use shorter names. In this case, make sure the sequence of characters does not mean something else.
