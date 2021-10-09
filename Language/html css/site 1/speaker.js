var speakerData = {
    "speakers": [
        {
            "index": "0",
            "imageURL": "Images/anton-atanasov-RW7q54akgjM-unsplash.jpg",
        },
        {
            "index": "1",
            "imageURL": "Images/hamid-tajik-FY-um1rfLOA-unsplash.jpg",
        },
        {
            "index": "2",
            "imageURL": "Images/insung-yoon-nFW4oOQ-ejk-unsplash.jpg",
        },
        {
            "index": "3",
            "imageURL": "Images/microsoft-edge-ZdBsz77QTaE-unsplash.jpg",
        },
        {
            "index": "4",
            "imageURL": "Images/thevaler_s-lIJ_rgBDUGM-unsplash.jpg",
        },
    ]
};



var currentIndex = 1;

function changeMain(direction) {
    if (direction == "left")
        traverseLeft(3);
    else if (direction == "right")
        traverseRight(3);

    alert("index" + currentIndex)
    updateList(currentIndex);
    //this.style.display = "none";
}

function traverseLeft(n) {
    if (currentIndex == 1) {
        currentIndex = n - 1;
    }
    else {
        currentIndex--;
    }
}

function traverseRight(n) {
    if (currentIndex == n - 1) {
        currentIndex = 1;
    }
    else {
        currentIndex++;
    }
}

function createSpeakers() {

    data = speakerData;
    ind = 0;
    var count = Object.keys(data["speakers"]).length;
    // alert(count);
    const carouselContainer = document.getElementsByClassName("carouselcontainer")[0];
    for (i in data["speakers"]) {
        console.log(i);
        ind++;
        tile = document.createElement("div");
        image = document.createElement("img");
        id = document.createElement("P");
        id.style.display = "none";
        id.innerText = i;
        //image.src = "Images/UXTopia Speaker Tile @rahul.png";
        image.src = data["speakers"][i]["imageURL"];
        tile.addEventListener("mouseover", event => {
            displayIndex(event.target)
        });
        console.log(data["speakers"][i]["imageURL"]);
        tile.appendChild(image);
        tile.appendChild(id);


        tile.classList.add("carouselitem");
        carouselContainer.appendChild(tile);

        // scrollIn(13);
        findScroll(currentIndex);

    }
}

function init() {
    j = 0;
    // /alert("hi");
    document.querySelectorAll('.carouselitem').forEach(item => {
        //alert(j++)
        item.addEventListener('mouseover', event => {

        })
    })
}



function displayIndex(i) {
    scrollIn(parseInt(i.parentNode.childNodes[1].innerText) + 1);
}



function findScroll(index) {
    //alert(index)
    const carouselContainer = document.getElementsByClassName("carouselcontainer")[0];
    const carouselWrapper = document.getElementsByClassName("carouselwrapper")[0];
    var rectangle = carouselContainer.childNodes[index].getBoundingClientRect();
    x = rectangle.left;
    y = rectangle.top;
    w = rectangle.width;
    h = rectangle.height;

    // alert("Left:" + x + ", Top:" + y +", Width:" + w + ", Height:" + h);
    carouselWrapper.scrollTo(x - 100, 0)
}

function scrollIn(index) {


    var count = Object.keys(data["speakers"]).length + 1;
    prevIndex = nextIndex = 0;

    //j = 0;
    const carouselContainer = document.getElementsByClassName("carouselcontainer")[0];
    //carouselContainer.scrollTo(100, 0);
    //alert(count + "-" + prevIndex + "-" + index + "-" + nextIndex + "+" + carouselContainer.childNodes.length)

    if (index == 1)
        prevIndex = count - 1;
    else
        prevIndex = index - 1;
    // if (index == count - 1)
    //     nextIndex = 1;
    // else
    nextIndex = parseInt(index) + 1;





    k = 1;
    for (j = 1; j < count; ++j) {
        //carouselContainer.childNodes[index].classList.add("itemLeft");
        carouselContainer.childNodes[j].style.transform = "rotate(0deg)";
        carouselContainer.childNodes[j].style.transform += "translate(0px,0px)";
        // if (carouselContainer.childNodes[j].classList.contains("itemLeft"))
        //     carouselContainer.childNodes[j].classList.remove("itemLeft");
        // if (carouselContainer.childNodes[j].classList.contains("itemRight"))
        //     carouselContainer.childNodes[j].classList.remove("itemRight");
        //if (carouselContainer.childNodes[j].classList.contains("itemCenter"))
        //carouselContainer.childNodes[j].classList.remove("itemCenter");
        if (j < index) {
            //carouselContainer.childNodes[j].classList.remove("itemRight");
            //carouselContainer.childNodes[j].classList.add("itemLeft");
            carouselContainer.childNodes[j].style.transform = "rotate(" + (index - j) * -10 + "deg)";
            //carouselContainer.childNodes[j].style.transform += "translate(0px," + -10 * j + "px)";
            carouselContainer.childNodes[j].style.transform += "scale(" + (100 - ((index - j) * 20)) + "%)";
        }
        if (j > index) {
            //carouselContainer.childNodes[index].classList.remove("itemLeft");
            //carouselContainer.childNodes[j].classList.add("itemRight");
            carouselContainer.childNodes[j].style.transform = "rotate(" + (k++) * 10 + "deg)";
            //carouselContainer.childNodes[j].style.transform += "translate(0px," + k * 30 + "px)";
            //carouselContainer.childNodes[j].style.transform += "scale(" + (((index - j) * 2) + 20) * "%)";
            carouselContainer.childNodes[j].style.transform += "scale(" + (100 - ((k - 1) * 20)) + "%)";
        }
        //carouselContainer.childNodes[j].classList.add("itemLeft");
    }
}

function changePos() {

    scrollIn(currentIndex);

    findScroll(currentIndex);
    var count = Object.keys(data["speakers"]).length;
    traverseRight(count);
}

function addtoEnd(index) {
    const carouselContainer = document.getElementsByClassName("carouselcontainer")[0];
    carouselContainer.appendChild(carouselContainer.firstChild);

}