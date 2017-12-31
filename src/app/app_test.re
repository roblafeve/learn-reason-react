open Jest;

open Expect;

test("addition", () =>
  expect(3 + 4) |> toBe(7)
);

test("subtraction", () =>
  expect(3 - 2) |> toBe(1)
);