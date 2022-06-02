#include <z3++.h>

using namespace z3;

int main(void)
{
  context ctx;
  expr x = ctx.int_const("x");
  expr y = ctx.int_const("y");
  expr equation1 = (x == y + 1);
  expr equation2 = (y == 2 * x);
  solver slv(ctx);
  slv.add(equation1);
  slv.add(equation2);
  check_result ok = slv.check();
  std::cout << ok << "\n";
  model mdl = slv.get_model();
  std::cout << mdl << "\n";
  return 0;
}
