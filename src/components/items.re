let component = ReasonReact.statelessComponent("Items");

let make = (~item, ~items, _children) => {
  ...component,
  render: _self =>
    switch items {
    | Some(is) =>
      List.map(item, is) |> Array.of_list |> ReasonReact.arrayToElement
    | None => ReasonReact.stringToElement("Loading...")
    }
};