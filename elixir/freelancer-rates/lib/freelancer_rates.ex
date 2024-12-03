defmodule FreelancerRates do
  defp billable_days(), do: 22

  defp discount_percentage(discount), do: (100 - discount) / 100

  defp hours_in_day(), do: 8.0

  def daily_rate(hourly_rate) do
    hours_in_day() * hourly_rate
  end

  def apply_discount(before_discount, discount) do
    before_discount * discount_percentage(discount)
  end

  def monthly_rate(hourly_rate, discount) do
    ceil(apply_discount(daily_rate(hourly_rate) * billable_days(), discount))
  end

  def days_in_budget(budget, hourly_rate, discount) do
    # amount = hourly_rate * hours * discount_percentage(discount)
    Float.floor(budget * 100 / (hourly_rate * (100 - discount)) / hours_in_day() * 10) / 10.0
  end
end
