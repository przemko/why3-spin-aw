#include <stdio.h>
#include <z3.h>

int main(void)
{
  Z3_config config = Z3_mk_config();
  Z3_context context = Z3_mk_context(config);
  Z3_del_config(config);
  Z3_solver solver = Z3_mk_solver(context);
  Z3_sort sort = Z3_mk_int_sort(context);
  Z3_symbol symbol_x = Z3_mk_string_symbol(context, "x");
  Z3_symbol symbol_y = Z3_mk_string_symbol(context, "y");
  Z3_ast x = Z3_mk_const(context, symbol_x, sort);
  Z3_ast y = Z3_mk_const(context, symbol_y, sort);
  Z3_ast one = Z3_mk_int64(context, 1, sort);
  Z3_ast two = Z3_mk_int64(context, 2, sort);
  Z3_ast args1[] = {y, one};
  Z3_ast add = Z3_mk_add(context, 2, args1);
  Z3_ast args2[] = {two, x};
  Z3_ast mul = Z3_mk_mul(context, 2, args2);
  Z3_ast equation1 = Z3_mk_eq(context, x, add);
  Z3_ast equation2 = Z3_mk_eq(context, y, mul);
  Z3_solver_assert(context, solver, equation1);
  Z3_solver_assert(context, solver, equation2);
  switch(Z3_solver_check(context, solver)) {
  case Z3_L_UNDEF:
    printf("unknown\n");
    break;
  case Z3_L_TRUE:
    printf("sat\n");
    Z3_model model = Z3_solver_get_model(context, solver);
    Z3_string string = Z3_model_to_string(context, model);
    printf("%s\n", string);
    break;
  case Z3_L_FALSE:
    printf("unsat\n");
  }
  return 0;
}
