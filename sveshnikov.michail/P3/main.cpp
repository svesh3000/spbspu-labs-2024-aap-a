#include "cnt_nzr_dig.hpp"

int main(int argc, char **argv)
{
  if (argc < 4)
  {
    std::cerr << "ERROR: Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "ERROR: Too many arguments\n";
    return 1;
  }
  for (size_t i = 0; argv[1][i] != '\0'; i++)
  {
    if (argv[1][i] < '0' || argv[1][i] > '9')
    {
      std::cerr << "ERROR: First parameter  is not a numberout\n";
      return 1;
    }
  }
  if (argv[1][1] != '\0' || !(argv[1][0] == '1' || argv[1][0] == '2'))
  {
    std::cerr << "ERROR: First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t num_rows = 0, num_columns = 0;
  input >> num_rows, num_columns;
  size_t read = 0;
  size_t num_diagonal = 0;
  if (argv[1][0] == '1' && argv[1][0] == '\0')
  {
    const size_t LEN = num_columns * num_rows;
    int matrix1[LEN] = {};
    if (!sveshnikov::read_matrix(std::cin, matrix1, num_rows, num_columns, read))
    {
      std::cerr << "ERROR: It cannot be interpreted as a two-dimensional array\n";
      return 1;
    }
    if (!sveshnikov::read_matrix(input, matrix1, num_rows, num_columns, read))
    {
      std::cerr << "ERROR: It cannot be interpreted as a two-dimensional array\n";
      return 1;
    }
    if (read != num_rows * num_columns)
    {
      std::cerr << "ERROR: First parameter is  is out of range\n";
      return 1;
    }
    num_diagonal = sveshnikov::cnt_nzr_dig(matrix1, num_rows, num_columns);
  }
  else if (argv[1][0] == '2' && argv[1][0] == '\0')
  {
    size_t len = num_columns * num_rows;
    int *matrix2 = new int[len];
    if (!sveshnikov::read_matrix(std::cin, matrix2, num_rows, num_columns, read))
    {
      std::cerr << "ERROR: It cannot be interpreted as a two-dimensional array\n";
      return 1;
    }
    if (!sveshnikov::read_matrix(input, matrix2, num_rows, num_columns, read))
    {
      std::cerr << "ERROR: It cannot be interpreted as a two-dimensional array\n";
      return 1;
    }
    if (read != num_rows * num_columns)
    {
      std::cerr << "ERROR: First parameter is  is out of range\n";
      return 1;
    }
    num_diagonal = sveshnikov::cnt_nzr_dig(matrix2, num_rows, num_columns);
  }
  else
  {
    std::cerr << "ERROR: First parameter is  is out of range\n";
    return 1;
  }
  std::ofstream output(argv[3]);
  output << num_diagonal;
}