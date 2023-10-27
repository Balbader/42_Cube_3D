# Raycasting

Using the player's coordinate and his looking angle we can calculate the ray's vector `(X and Y components)`. Then calculate the offset `(gridline outlier)` the points where the rays could hit vertically and horizontally till the point of the wall.

## Horizontal and Vertical check
Horizontal Grid Lines is the (NORTH & SOUTH), or `the upper and the lower sides of a 2d map`. Vertical Grid Lines is the (WEST & EAST), `or the left and the right sides of a 2d map`. Depending on the looking angle of the player we can decide where the ray is actually hitting vertically `(left or right)` and horizontally `(up or down)`. Before that We actually need to understand how we can calculate `the ray's line and the ray's vector`.

# Offset
Offset basically means the amount or value by which the calculation is out of line or where it could hit the outlier. And here it means the value to add each time to hit the next grid line. So, we want the rays to hit the grid lines not more not less.