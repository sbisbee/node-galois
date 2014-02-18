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

Handle<Value> shift_multiply(const Arguments& args) {
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
    ::galois_shift_multiply(
      args[0]->ToInteger()->Value(),
      args[1]->ToInteger()->Value(),
      args[2]->ToInteger()->Value()));

  return scope.Close(num);
}

Handle<Value> shift_divide(const Arguments& args) {
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
    ::galois_shift_divide(
      args[0]->ToInteger()->Value(),
      args[1]->ToInteger()->Value(),
      args[2]->ToInteger()->Value()));

  return scope.Close(num);
}

Handle<Value> inverse(const Arguments& args) {
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
    ::galois_inverse(
      args[0]->ToInteger()->Value(),
      args[1]->ToInteger()->Value()));

  return scope.Close(num);
}

Handle<Value> shift_inverse(const Arguments& args) {
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
    ::galois_shift_inverse(
      args[0]->ToInteger()->Value(),
      args[1]->ToInteger()->Value()));

  return scope.Close(num);
}

Handle<Value> create_mult_tables(const Arguments& args) {
  HandleScope scope;
  Handle<Boolean> succ;
  int w;

  if(args.Length() < 1) {
    ThrowException(Exception::TypeError(String::New("Wrong number of args")));
    return scope.Close(Undefined());
  }

  if(!args[0]->IsNumber()) {
    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
    return scope.Close(Undefined());
  }

  w = args[0]->ToInteger()->Value();

  if(w < 1 || w >= 14) {
    ThrowException(Exception::Error(String::New("Invalid w (0 < w < 14)")));
    return scope.Close(Undefined());
  }

  succ = Boolean::New(galois_create_mult_tables(w) == 0);

  return scope.Close(succ);
}

Handle<Value> multtable_multiply(const Arguments& args) {
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
    galois_multtable_multiply(
      args[0]->ToInteger()->Value(),
      args[1]->ToInteger()->Value(),
      args[2]->ToInteger()->Value()));

  return scope.Close(num);
}

Handle<Value> multtable_divide(const Arguments& args) {
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
    galois_multtable_divide(
      args[0]->ToInteger()->Value(),
      args[1]->ToInteger()->Value(),
      args[2]->ToInteger()->Value()));

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

  exports->Set(String::NewSymbol("shift_multiply"),
    FunctionTemplate::New(shift_multiply)->GetFunction());

  exports->Set(String::NewSymbol("shift_divide"),
    FunctionTemplate::New(shift_divide)->GetFunction());

  exports->Set(String::NewSymbol("inverse"),
    FunctionTemplate::New(inverse)->GetFunction());

  exports->Set(String::NewSymbol("shift_inverse"),
    FunctionTemplate::New(shift_inverse)->GetFunction());

  exports->Set(String::NewSymbol("create_mult_tables"),
    FunctionTemplate::New(create_mult_tables)->GetFunction());

  exports->Set(String::NewSymbol("multtable_multiply"),
    FunctionTemplate::New(multtable_multiply)->GetFunction());

  exports->Set(String::NewSymbol("multtable_divide"),
    FunctionTemplate::New(multtable_divide)->GetFunction());
}

NODE_MODULE(galoisjs, Init)
