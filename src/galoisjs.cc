/*
 * node-galois
 * Copyright (C) 2014 Sam Bisbee
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

Handle<Value> create_log_tables(const Arguments& args) {
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

  if(w < 1 || w > 30) {
    ThrowException(Exception::Error(String::New("Invalid w (0 < w < 31)")));
    return scope.Close(Undefined());
  }

  succ = Boolean::New(galois_create_log_tables(w) == 0);

  return scope.Close(succ);
}

Handle<Value> logtable_multiply(const Arguments& args) {
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
    galois_logtable_multiply(
      args[0]->ToInteger()->Value(),
      args[1]->ToInteger()->Value(),
      args[2]->ToInteger()->Value()));

  return scope.Close(num);
}

Handle<Value> logtable_divide(const Arguments& args) {
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
    galois_logtable_divide(
      args[0]->ToInteger()->Value(),
      args[1]->ToInteger()->Value(),
      args[2]->ToInteger()->Value()));

  return scope.Close(num);
}

Handle<Value> create_split_w8_tables(const Arguments& args) {
  HandleScope scope;
  Handle<Boolean> succ;

  if(args.Length() >= 1) {
    ThrowException(Exception::TypeError(String::New("Wrong number of args")));
    return scope.Close(Undefined());
  }

  succ = Boolean::New(galois_create_split_w8_tables() == 0);

  return scope.Close(succ);
}

Handle<Value> split_w8_multiply(const Arguments& args) {
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
    galois_split_w8_multiply(
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

  exports->Set(String::NewSymbol("create_log_tables"),
    FunctionTemplate::New(create_log_tables)->GetFunction());

  exports->Set(String::NewSymbol("logtable_multiply"),
    FunctionTemplate::New(logtable_multiply)->GetFunction());

  exports->Set(String::NewSymbol("logtable_divide"),
    FunctionTemplate::New(logtable_divide)->GetFunction());

  exports->Set(String::NewSymbol("create_split_w8_tables"),
    FunctionTemplate::New(create_split_w8_tables)->GetFunction());

  exports->Set(String::NewSymbol("split_w8_multiply"),
    FunctionTemplate::New(split_w8_multiply)->GetFunction());
}

NODE_MODULE(galoisjs, Init)
