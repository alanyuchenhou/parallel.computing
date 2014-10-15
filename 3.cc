int GetMyMate (int r)
{
  int mesh_dimention = static_cast<int>(sqrt(p));
  int row = r / mesh_dimention;
  int column = r % mesh_dimention;
  return column*mesh_dimention + row;
}
