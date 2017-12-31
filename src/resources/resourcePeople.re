let decodePeople = json : Data.person =>
  Json.Decode.{
    url: field("url", string, json),
    name: field("name", string, json),
    id: field("name", string, json),
    birthYear: field("birth_year", string, json)
  };

let parseResults = json : Data.people =>
  Json.Decode.field("results", Json.Decode.list(decodePeople), json);

let get = handler =>
  Js.Promise.(
    Fetch.fetch("https://swapi.co/api/people")
    |> then_(Fetch.Response.json)
    |> then_(json => parseResults(json) |> resolve)
    |> then_(parsed => handler(parsed) |> resolve)
    |> ignore
  );