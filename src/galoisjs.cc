#include <node.h>
#include <v8.h>
#include <galois.h>

using namespace v8;

Handle<Value> single_multiply(const Arguments& args) {
  HandleScope scope;
  Local<Number> num;

  if(args.Length() < 3) {
    ThrowException(Exception::TypeError(String::New("Wrong number of args")));
    return scope.Close(Undefined());
  }

  if(!args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsNumber()) {
    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
    return scope.Close(Undefined());
  }

  num = Number::New(
    ::galois_single_multiply(
      args[0]->ToInteger()->Value(),
      args[1]->ToInteger()->Value(),
      args[2]->ToInteger()->Value()));

  return scope.Close(num);
}

Handle<Value> single_divide(const Arguments& args) {
  HandleScope scope;
  Local<Number> num;

  if(args.Length() < 3) {
    ThrowException(Exception::TypeError(String::New("Wrong number of args")));
    return scope.Close(Undefined());
  }

  if(!args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsNumber()) {
    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
    return scope.Close(Undefined());
  }

  num = Number::New(
    ::galois_single_divide(
      args[0]->ToInteger()->Value(),
      args[1]->ToInteger()->Value(),
      args[2]->ToInteger()->Value()));

  return scope.Close(num);
}

Handle<Value> log(const Arguments& args) {
  HandleScope scope;
  Local<Number> num;

  if(args.Length() < 2) {
    ThrowException(Exception::TypeError(String::New("Wrong number of args")));
    return scope.Close(Undefined());
  }

  if(!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
    return scope.Close(Undefined());
  }

  num = Number::New(
    ::galois_log(
      args[0]->ToInteger()->Value(),
      args[1]->ToInteger()->Value()));

  return scope.Close(num);
}

Handle<Value> ilog(const Arguments& args) {
  HandleScope scope;
  Local<Number> num;

  if(args.Length() < 2) {
    ThrowException(Exception::TypeError(String::New("Wrong number of args")));
    return scope.Close(Undefined());
  }

  if(!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
    return scope.Close(Undefined());
  }

  num = Number::New(
    ::galois_ilog(
      args[0]->ToInteger()->Value(),
      args[1]->ToInteger()->Value()));

  return scope.Close(num);
}

static void Init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("single_multiply"),
    FunctionTemplate::New(single_multiply)->GetFunction());

  exports->Set(String::NewSymbol("single_divide"),
    FunctionTemplate::New(single_divide)->GetFunction());

  exports->Set(String::NewSymbol("log"),
    FunctionTemplate::New(log)->GetFunction());

  exports->Set(String::NewSymbol("ilog"),
    FunctionTemplate::New(ilog)->GetFunction());
}

NODE_MODULE(galoisjs, Init)
