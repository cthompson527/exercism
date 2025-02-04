defmodule Secrets do
  def secret_add(secret) do
    # Please implement the secret_add/1 function
    fn x -> secret + x end
  end

  def secret_subtract(secret) do
    fn x -> x - secret end
  end

  def secret_multiply(secret) do
    fn x -> x * secret end
  end

  def secret_divide(secret) do
    fn x -> div(x, secret) end
  end

  def secret_and(secret) do
    fn x -> Bitwise.band(secret, x) end
  end

  def secret_xor(secret) do
    fn x -> Bitwise.bxor(secret, x) end
  end

  def secret_combine(secret_function1, secret_function2) do
    fn x -> secret_function2.(secret_function1.(x)) end
  end
end
