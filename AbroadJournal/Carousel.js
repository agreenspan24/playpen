function addCarousel(pics, title) {
	var CarouselString = '<div id="myCarousel" class="carousel slide" data-ride="carousel"><ol class="carousel-indicators"><li data-target="#myCarousel" data-slide-to="0" class="active"></li>';
	
	for (var i = 1; i < pics.length; i++){
		CarouselString += '<li data-target="#myCarousel" data-slide-to="' + i + '"></li>';
	}

	CarouselString += '</ol><div class="carousel-inner" role="listbox">';

	for (var i = 0; i < pics.length; i++){
		CarouselString += '<div class="item';
		if (i == 0) {CarouselString += ' active';}
		CarouselString += '"><img height="300" src="pics/' + title + '/' + pics[i].ref + '" alt="' + pics[i].name + '"><div class="carousel-caption"><h3>' + pics[i].name + '</h3></div></div>'
	}

	CarouselString += '</div><a class="left carousel-control" href="#myCarousel" role="button" data-slide="prev"><span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span><span class="sr-only">Previous</span></a><a class="right carousel-control" href="#myCarousel" role="button" data-slide="next"><span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span><span class="sr-only">Next</span></a></div>';

	$("#theCarousel").html(CarouselString);
	console.log(CarouselString);
}



