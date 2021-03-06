//
// Created by squadrick on 10/10/19.
//
#include <iostream>
#include <msgpack.hpp>
#include <shadesmar/custom_msg.h>

int main() {
  CustomMessage cm(5);
  cm.seq = 1;
  cm.frame_id = "test123";
  cm.init_time();
  cm.im.inner_val = 100;
  cm.im.inner_str = "Dheeraj";

  std::cout << cm.timestamp << std::endl;

  msgpack::sbuffer buf;
  msgpack::pack(buf, cm);

  std::cout << buf.data() << std::endl;

  msgpack::object_handle res = msgpack::unpack(buf.data(), buf.size());
  msgpack::object obj = res.get();
  std::cout << obj << std::endl;

  CustomMessage mc;
  obj.convert(mc);

  DEBUG(mc.seq);
  DEBUG(mc.frame_id);
  DEBUG(mc.timestamp);
  DEBUG(mc.im.inner_val);
  DEBUG(mc.im.inner_str);

  for (auto &x : mc.arr)
    DEBUG_IMPL(x, " ");
  DEBUG("");
}