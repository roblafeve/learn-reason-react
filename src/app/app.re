let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self => <div className="App"> 
    <h1>(ReasonReact.stringToElement("Star Wars People"))</h1>
    <ItemsPeople /> 
  </div>
};