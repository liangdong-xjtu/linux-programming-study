
// g++ -D _GNU_SOURCE -D _XOPEN_SOURCE -D _POSIX_C_SOURCE -o gnu-source-test gnu-source-test.c

#include <iostream>

int main()
{
#ifdef _GNU_SOURCE
  std::cout << "gnu\n";
#else
  std::cout << "non-gnu\n";
#endif
#ifdef _XOPEN_SOURCE
  std::cout << "_XOPEN_SOURCE\n";
#else
  std::cout << "non _XOPEN_SOURCE\n";
#endif
#ifdef _POSIX_C_SOURCE
#if _POSIX_C_SOURCE >= 2
  std::cout << "_POSIX_C_SOURCE >= 2\n";
#else
  std::cout << "_POSIX_C_SOURCE < 2\n";
#endif
#else
  std::cout << "non _POSIX_C_SOURCE\n";
#endif
}

