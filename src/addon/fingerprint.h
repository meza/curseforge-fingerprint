#include <iostream>
#include <vector>

namespace fingerprint {
  typedef std::vector<unsigned char> Buffer;
  void print_usage();
  Buffer get_jar_contents(const char* jar_file_path);
  long get_file_size(FILE* file);
  uint32_t compute_hash(Buffer& buffer);
  bool is_whitespace_character(char b);
  uint32_t compute_normalized_length(Buffer& buffer);
}
