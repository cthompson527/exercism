import gleam/list
import gleam/string

pub fn message(log_line: String) -> String {
  log_line
  |> string.split(on: ":")
  |> list.drop(up_to: 1)
  |> string.join(with: "")
  |> string.trim()
}

pub fn log_level(log_line: String) -> String {
  case log_line {
    "[ERROR]" <> _ -> "error"
    "[WARNING]" <> _ -> "warning"
    _ -> "info"
  }
}

pub fn reformat(log_line: String) -> String {
  let message = message(log_line)
  let log_level = log_level(log_line)
  message <> " (" <> log_level <> ")"
}
