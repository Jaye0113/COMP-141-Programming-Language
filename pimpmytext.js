// 增加字体大小
function fontSize() {
    var textArea = document.getElementById("sampletext");
    var style = window.getComputedStyle(textArea, null).getPropertyValue('font-size');
    var currentSize = parseFloat(style);
    textArea.style.fontSize = (currentSize + 2) + 'pt';
}

// 添加/移除样式
function textStyle() {
    var textArea = document.getElementById("sampletext");
    if (document.getElementById("pimp").checked) {
        textArea.style.fontWeight = "bold";
        textArea.style.color = "green";
        textArea.style.textDecoration = "underline";
    } else {
        textArea.style.fontWeight = "normal";
        textArea.style.color = "black";
        textArea.style.textDecoration = "none";
    }
}

// 修改文本内容
function snoopify() {
    var textArea = document.getElementById("sampletext");
    textArea.value = textArea.value.toUpperCase() + " SNOOP DOGG!";
}
