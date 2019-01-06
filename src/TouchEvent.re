 module Touch = {
  module Touch = {
    type t = {
      .
      "identifier": string,
      "clientX": int,
      "clientY": int,
      "screenX": int,
      "screenY": int,
      "pageX": int,
      "pageY": int,
      "target": Dom.element,
    };
  };

  external castDomTouchListToTouchArray :
    Webapi.Dom.TouchEvent.touchList => array(Touch.t) =
    "%identity";
  external castReactTouchListToTouchArray : Js.t({..}) => array(Touch.t) =
    "%identity";
  external castEventToTouchEvent : Dom.event => Dom.touchEvent = "%identity";
}
