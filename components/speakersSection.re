module Link = ReactRouterDom.Link;

open Util;

[@bs.module] external style: Js.t({..}) = "./speakersSection.module.scss";

let component = ReasonReact.statelessComponent("SpeakersSection");

let speakerColumn = (speaker: Data.Speaker.t) =>
  <li className=style##listItem key={speaker.name}>
    <Link to_={"/speakers/#" ++ Data.Speaker.speakerAnchor(speaker)}>
      <SpeakerCard speaker />
    </Link>
  </li>;

let make = _children => {
  ...component,
  render: _self =>
    <section className=style##root>
      <div className="container">
        <h1> {"Speakers" |> s} </h1>
        <ParallaxScroll
          from="top-bottom"
          to_="bottom-top"
          props={
            "--speakers-ty": {
              "from": "100px",
              "to": "-100px",
            },
          }>
          ...<ul className=style##list>
               {
                 Data.Speaker.speakers
                 |> Array.map(speakerColumn)
                 |> ReasonReact.array
               }
             </ul>
        </ParallaxScroll>
      </div>
    </section>,
};
