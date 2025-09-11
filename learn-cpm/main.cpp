#include <backward.hpp>
#include <fmt/core.h>
#include <spdlog/spdlog.h>

void backward_trace() {
  backward::StackTrace st;
  st.load_here(32);
  backward::Printer p;
  p.print(st);
}

int main() {
  fmt::print("Hello World!\n");
  spdlog::info("hello {}", "world");
  spdlog::debug("debug {}", 123);
  spdlog::warn("warn {}", 456);
  spdlog::error("error {}", 789);

  spdlog::info("backward-cpp trace");
  backward_trace();

  spdlog::error("xxx {}", 1 / 0);

  return 0;
}
