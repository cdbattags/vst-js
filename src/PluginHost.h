#ifndef PLUGINHOST_H

#define PLUGINHOST_H

#include "../../shared/JuceLibraryCode/JuceHeader.h"
#include "iobuffer.pb.h"
#include "zhelpers.hpp"
#include <nan.h>

class PluginHost : public Nan::ObjectWrap {
public:
  static void Init();
  static v8::Local<v8::Object> NewInstance(v8::Local<v8::Value> arg);
  static void Start(const Nan::FunctionCallbackInfo<v8::Value> &info);
  static void Stop(const Nan::FunctionCallbackInfo<v8::Value> &info);
  juce::ChildProcess proc;
  static void
  ProcessAudioBlock(const Nan::FunctionCallbackInfo<v8::Value> &info);
  zmq::context_t context;
  zmq::socket_t socket;
  String socketAddress;

private:
  PluginHost(String _socketAddress);
  ~PluginHost();

  static Nan::Persistent<v8::Function> constructor;
  static void New(const Nan::FunctionCallbackInfo<v8::Value> &info);
};

#endif