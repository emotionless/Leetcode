<h2><a href="https://leetcode.com/problems/find-books-with-no-available-copies">3570. Find Books with No Available Copies</a></h2><h3>Easy</h3><hr><p>Table: <code>library_books</code></p>

<pre>
+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| book_id          | int     |
| title            | varchar |
| author           | varchar |
| genre            | varchar |
| publication_year | int     |
| total_copies     | int     |
+------------------+---------+
book_id is the unique identifier for this table.
Each row contains information about a book in the library, including the total number of copies owned by the library.
</pre>

<p>Table: <code>borrowing_records</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| record_id     | int     |
| book_id       | int     |
| borrower_name | varchar |
| borrow_date   | date    |
| return_date   | date    |
+---------------+---------+
record_id is the unique identifier for this table.
Each row represents a borrowing transaction and return_date is NULL if the book is currently borrowed and hasn&#39;t been returned yet.
</pre>

<p>Write a solution to find <strong>all books</strong> that are <strong>currently borrowed (not returned)</strong> and have <strong>zero copies available</strong> in the library.</p>

<ul>
	<li>A book is considered <strong>currently borrowed</strong> if there exists a<strong> </strong>borrowing record with a <strong>NULL</strong> <code>return_date</code></li>
</ul>

<p>Return <em>the result table ordered by current borrowers in <strong>descending</strong> order, then by book title in <strong>ascending</strong> order.</em></p>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example:</strong></p>

<div class="example-block">
<p><strong>Input:</strong></p>

<p>library_books table:</p>

<pre class="example-io">
+---------+------------------------+------------------+----------+------------------+--------------+
| book_id | title                  | author           | genre    | publication_year | total_copies |
+---------+------------------------+------------------+----------+------------------+--------------+
| 1       | The Great Gatsby       | F. Scott         | Fiction  | 1925             | 3            |
| 2       | To Kill a Mockingbird  | Harper Lee       | Fiction  | 1960             | 3            |
| 3       | 1984                   | George Orwell    | Dystopian| 1949             | 1            |
| 4       | Pride and Prejudice    | Jane Austen      | Romance  | 1813             | 2            |
| 5       | The Catcher in the Rye | J.D. Salinger    | Fiction  | 1951             | 1            |
| 6       | Brave New World        | Aldous Huxley    | Dystopian| 1932             | 4            |
+---------+------------------------+------------------+----------+------------------+--------------+
</pre>

<p>borrowing_records table:</p>

<pre class="example-io">
+-----------+---------+---------------+-------------+-------------+
| record_id | book_id | borrower_name | borrow_date | return_date |
+-----------+---------+---------------+-------------+-------------+
| 1         | 1       | Alice Smith   | 2024-01-15  | NULL        |
| 2         | 1       | Bob Johnson   | 2024-01-20  | NULL        |
| 3         | 2       | Carol White   | 2024-01-10  | 2024-01-25  |
| 4         | 3       | David Brown   | 2024-02-01  | NULL        |
| 5         | 4       | Emma Wilson   | 2024-01-05  | NULL        |
| 6         | 5       | Frank Davis   | 2024-01-18  | 2024-02-10  |
| 7         | 1       | Grace Miller  | 2024-02-05  | NULL        |
| 8         | 6       | Henry Taylor  | 2024-01-12  | NULL        |
| 9         | 2       | Ivan Clark    | 2024-02-12  | NULL        |
| 10        | 2       | Jane Adams    | 2024-02-15  | NULL        |
+-----------+---------+---------------+-------------+-------------+
</pre>

<p><strong>Output:</strong></p>

<pre class="example-io">
+---------+------------------+---------------+-----------+------------------+-------------------+
| book_id | title            | author        | genre     | publication_year | current_borrowers |
+---------+------------------+---------------+-----------+------------------+-------------------+
| 1       | The Great Gatsby | F. Scott      | Fiction   | 1925             | 3                 | 
| 3       | 1984             | George Orwell | Dystopian | 1949             | 1                 |
+---------+------------------+---------------+-----------+------------------+-------------------+
</pre>

<p><strong>Explanation:</strong></p>

<ul>
	<li><strong>The Great Gatsby (book_id = 1):</strong>

	<ul>
		<li>Total copies: 3</li>
		<li>Currently borrowed by Alice Smith, Bob Johnson, and Grace Miller (3 borrowers)</li>
		<li>Available copies: 3 - 3 = 0</li>
		<li>Included because available_copies = 0</li>
	</ul>
	</li>
	<li><strong>1984 (book_id = 3):</strong>
	<ul>
		<li>Total copies: 1</li>
		<li>Currently borrowed by David Brown (1 borrower)</li>
		<li>Available copies: 1 - 1 = 0</li>
		<li>Included because available_copies = 0</li>
	</ul>
	</li>
	<li><strong>Books not included:</strong>
	<ul>
		<li>To Kill a Mockingbird (book_id = 2): Total copies = 3, current borrowers = 2, available = 1</li>
		<li>Pride and Prejudice (book_id = 4): Total copies = 2, current borrowers = 1, available = 1</li>
		<li>The Catcher in the Rye (book_id = 5): Total copies = 1, current borrowers = 0, available = 1</li>
		<li>Brave New World (book_id = 6): Total copies = 4, current borrowers = 1, available = 3</li>
	</ul>
	</li>
	<li><strong>Result ordering:</strong>
	<ul>
		<li>The Great Gatsby appears first with 3 current borrowers</li>
		<li>1984 appears second with 1 current borrower</li>
	</ul>
	</li>
</ul>

<p>Output table is ordered by current_borrowers in descending order, then by book_title in ascending order.</p>
</div>
