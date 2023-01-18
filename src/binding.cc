#include <napi.h>
#include <iostream>
#include <vector>

typedef std::vector<unsigned char> Buffer;

void print_usage();
Buffer get_jar_contents(const char* jar_file_path);
long get_file_size(FILE* file);
uint32_t compute_hash(Buffer& buffer);
bool is_whitespace_character(char b);
uint32_t compute_normalized_length(Buffer& buffer);

Napi::Value HashIt(const Napi::CallbackInfo& args) {
  Napi::Env env = args.Env();

  if (args.Length() < 1) {
    Napi::TypeError::New(env, "No file path given")
        .ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!args[0].IsString()) {
    Napi::TypeError::New(env, "File path must be a string").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::String path = args[0].As<Napi::String>();
  std::string path_u8 = path.Utf8Value();
  char* jar_file_path = (char*)path_u8.c_str();

  Buffer jar_buffer = get_jar_contents(jar_file_path);
    if (jar_buffer.empty()) {
      Napi::TypeError::New(env, "Jar file was empty").ThrowAsJavaScriptException();
          return env.Null();
    }

    const Napi::Number hash = Napi::Number::New(env, compute_hash(jar_buffer));

    return hash;
}

Buffer get_jar_contents(const char* jar_file_path) {
  int result;
  FILE* jar_file = fopen(jar_file_path, "rb");
  if (jar_file == nullptr) {
    return Buffer();
  }

  long buffer_size = get_file_size(jar_file);

  Buffer buffer(buffer_size);
  result = fread(buffer.data(), 1, buffer_size, jar_file);

  if (result != buffer_size) {
    std::cout << "Failed to load " << jar_file_path << std::endl;
  }

  fclose(jar_file);

  return buffer;
}

long get_file_size(FILE* file) {
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  fseek(file, 0, SEEK_SET);

  return size;
}

uint32_t compute_hash(Buffer& buffer) {
  const uint32_t multiplex = 1540483477;
  const uint32_t length = buffer.size();
  uint32_t num1 = length;

  num1 = compute_normalized_length(buffer);

  uint32_t num2 = (uint32_t)1 ^ num1;
  uint32_t num3 = 0;
  uint32_t num4 = 0;

  for (uint32_t index = 0; index < length; ++index) {

    unsigned char b = buffer[index];

    if (!is_whitespace_character(b)) {
      num3 |= (uint32_t)b << num4;
      num4 += 8;
      if (num4 == 32) {
        uint32_t num6 = num3 * multiplex;

        uint32_t num7 = (num6 ^ num6 >> 24) * multiplex;

        num2 = num2 * multiplex ^ num7;
        num3 = 0;
        num4 = 0;
      }
    }
  }

  if (num4 > 0) {
    num2 = (num2 ^ num3) * multiplex;
  }

  uint32_t num6 = (num2 ^ num2 >> 13) * multiplex;

  return num6 ^ num6 >> 15;
}

uint32_t compute_normalized_length(Buffer& buffer) {
  int32_t num1 = 0;
  const uint32_t length = buffer.size();

  for (uint32_t index = 0; index < length; ++index) {
    if (!is_whitespace_character(buffer[index])) {
      ++num1;
    }
  }

  return num1;
}

bool is_whitespace_character(char b) {
  return b == 9 || b == 10 || b == 13 || b == 32;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "fingerprint"), Napi::Function::New(env, HashIt));
  return exports;
}

NODE_API_MODULE(curseforge, Init);

