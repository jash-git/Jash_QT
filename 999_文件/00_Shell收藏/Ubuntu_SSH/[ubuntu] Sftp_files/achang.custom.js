jQuery(document).ready(function(e){
$("#social-share ul li a.pop").on('click', openPopup);
	function openPopup() {
		var _url    = $(this).data('shareurl'),
		    _title  = $(this).attr('title'),
	     	 left   = (screen.width/2)-(650/2),
	         top    = (screen.height/2)-(450/2),
	         popbox = window.open(_url, "popup", "width=650, height=450, top="+top+", left="+left);
	    return false;
	}
});
jQuery(document).ready(function(e) {
	var $sidebar = $("#share-box"),
		$window = $(window),
		offset = $sidebar.offset(), topPadding = 55;
		if(typeof(offset)!=="undefined"){
			$window.scroll(function() {
				if ($window.scrollTop() > offset.top) {
					$sidebar.stop().animate({
						marginTop: $window.scrollTop() - offset.top + topPadding
					});
				}
				else {
					$sidebar.stop().animate({ marginTop: 0 });
				}
			});
		}
});
jQuery(document).ready(function(e) {
  $(".fbbox").hover(function(){
      $(this).stop().animate({right: "0"}, "slow");
      }, function(){
        $(this).stop().animate({right: "-250"}, "slow");
  }, 500);
});

