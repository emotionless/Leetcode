# Write your MySQL query statement below

SELECT 
    lb.book_id, title, author, genre, publication_year, total_copies as  current_borrowers
FROM library_books lb 
WHERE 
    total_copies = ( SELECT COUNT(*) FROM borrowing_records br where lb.book_id = br.book_id AND br.return_date is NULL)
ORDER BY total_copies DESC, title ASC;