export function setCurrentCss(path) {
    const currentCSS = "bg-orange-700 text-white".split(" ")
    const defaultCSS = "text-orange-200 hover:text-white hover:bg-orange-700".split(" ")
    
    let node = document.querySelectorAll("nav a")
    
    for (let index = 0; index < node.length; index++) {
        let Element = node[index];
    
        if (Element.innerText == path) {
            Element.classList.add(...currentCSS)
        }else {
            Element.classList.remove(...currentCSS)
            Element.classList.add(...defaultCSS)
        }
        
    }
}

export function isInt(value) {
    if (isNaN(value)) {
    return false;
    }
    
     var x = parseFloat(value);
     return (x | 0) === x;
}