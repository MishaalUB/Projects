
class Dialog {
  constructor(text) {
    $("#dialog-container").empty();
    $("#inputs-container").empty();
    $("#dialog-container").append("<div class=\"dialog alert alert-secondary w-100 shadow p-4 mb-5 bg-white border-0\" style=\"border-radius: 15px;\"><p>" + text + "</p></div>");
  }
}

class Button {
  constructor(text, callback) {
    let button = $("<button/>", {
      text: text,
      click: callback,
      "class": "btn btn-primary m-2 w-100"
    });
    let parent = $("<div class=\"col h-100\"></div>").append(button);
    $("#inputs-container").append(parent);
  }
}