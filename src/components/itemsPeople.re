open ReasonReact;

open Theme;

type state = {people: option(Data.people)};

type action =
  | Loaded(Data.people);

let component = reducerComponent("ItemsPeople");

let styles =
  Css.(
    {
      "card":
        style([
          backgroundColor(white),
          boxShadow(shadow(~y=1, ~blur=3, rgba(0, 0, 0, 0.15))),
          padding(basePadding),
          marginTop(10 |> px),
          display(Flex),
          borderRadius(px(5))
        ]),
      "name": style([flexGrow(1)]),
      "info": style([fontSize(px(12))])
    }
  );

let item = (x: Data.person) =>
  <div key=x.id className=styles##card>
    <div className=styles##name> (stringToElement(x.name)) </div>
    <div className=styles##info>
      (stringToElement("Birth Year: " ++ x.birthYear))
    </div>
  </div>;

let make = _children => {
  ...component,
  initialState: () => {people: None},
  didMount: self => {
    ResourcePeople.get(self.reduce(res => Loaded(res)));
    ReasonReact.NoUpdate;
  },
  reducer: (action, _state) =>
    switch action {
    | Loaded(people) => ReasonReact.Update({people: Some(people)})
    },
  render: self => <Items item items=self.state.people />
};