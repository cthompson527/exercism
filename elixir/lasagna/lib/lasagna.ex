defmodule Lasagna do
  defp expected_minutes(), do: 40

  defp prep_time_per_layer(), do: 2

  # Please define the 'expected_minutes_in_oven/0' function
  def expected_minutes_in_oven(), do: expected_minutes()

  # Please define the 'remaining_minutes_in_oven/1' function
  def remaining_minutes_in_oven(actual), do: expected_minutes() - actual

  # Please define the 'preparation_time_in_minutes/1' function
  def preparation_time_in_minutes(layers), do: prep_time_per_layer() * layers

  # Please define the 'total_time_in_minutes/2' function
  def total_time_in_minutes(layers, actual), do: preparation_time_in_minutes(layers) + actual

  # Please define the 'alarm/0' function
  def alarm(), do: "Ding!"
end
