# Latex Template for technical reports
Latex template for technical reports.
This is mainly for mathematical explaination that do not fit in an article.

Examples of this template in use can be found [here](https://github.com/norlab-ulaval?utf8=%E2%9C%93&q=in%3Aname%technicalReport%20NOT%20template-technicalReport&type=&language=tex).

# How to Use
1. Create an empty repository on norlab-ulaval GitHub. Name it `technicalReport-<yourTopic>`.
1. Copy the content of this repository.
1. Rename the file `technicalReport.tex` to `technicalReport-<yourTopic>.tex`. This is your main document to fill.
1. In `technicalReport-<yourTopic>.tex`, fill the variables at the beginning of the file.
1. If your not familiar with the lab's good practices in Latex, read the file [preamble.tex](https://github.com/norlab-ulaval/latexGoodPractices/blob/master/preamble.tex).
1. In the core of the document, replace the commands `\lightlipsum[..]` by your text.
1. Iterate with your supervisor for some feedbacks.

# How to Modify
__Warning:__ There is a submodule in this repository. 
You will need to use `git clone --recursive git://github.com/foo/bar.git` to clone properly this repository.
Try to keep is consistent with the lastest version of the repository [latexGoodPractices](https://github.com/norlab-ulaval/latexGoodPractices).

Don't hesitate to update through pull request.
If you can save time to other, the all lab gets more efficient so we can do more research instead of formating text...
