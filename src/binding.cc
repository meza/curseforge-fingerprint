#include <node_api.h>
#include <assert.h>
#include <cstring>
#include <iostream>

#include "fingerprint.h"

napi_value HashIt(napi_env env, const napi_callback_info info) {
  napi_status status;
  size_t argc = 1;
  napi_value args[1];
  napi_value result;
  napi_valuetype type;

  status = napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
  assert(status == napi_ok);

  if (argc < 1) {
    napi_throw_error(env, NULL, "Please specify a file path");
    return 0;
  }

  // Parse jar path from args
  const char* jar_file_path = NULL;
  size_t jar_file_pathl;

  status = napi_typeof(env, args[0], &type);
  if (type != napi_string)
  {
    status = napi_create_string_utf8(env, "Please use a string for the pat", NAPI_AUTO_LENGTH, &result);
    return result;
  }

  status = napi_get_value_string_utf8(env, args[0], NULL, 0, &jar_file_pathl);
  jar_file_path = (char *)malloc(jar_file_pathl + 1);
  status = napi_get_value_string_utf8(env, args[0], (char *)jar_file_path, jar_file_pathl + 1, &jar_file_pathl);
  assert(status == napi_ok);

  fingerprint::Buffer jar_buffer = fingerprint::get_jar_contents(jar_file_path);

  if (jar_buffer.empty()) {
    napi_throw_error(env, NULL, "Jar file was empty");
    return 0;
  }

  napi_value hash;
  status = napi_create_uint32(env, fingerprint::compute_hash(jar_buffer), &hash);
  assert(status == napi_ok);

  return hash;
}

napi_value Init(napi_env env, napi_value exports) {
    napi_property_descriptor export_properties[] = {
  	{
  		"fingerprint", nullptr, HashIt,
  		nullptr, nullptr, nullptr, napi_default, nullptr
  	}
      };
      assert(napi_define_properties(env, exports,
  	sizeof(export_properties) / sizeof(export_properties[0]), export_properties) == napi_ok);

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)

